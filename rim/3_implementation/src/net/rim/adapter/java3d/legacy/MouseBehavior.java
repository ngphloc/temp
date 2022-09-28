package net.rim.adapter.java3d.legacy;

import java.awt.AWTEvent;
import java.awt.Component;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.util.Enumeration;
import java.util.LinkedList;

import javax.media.j3d.Behavior;
import javax.media.j3d.Transform3D;
import javax.media.j3d.WakeupCriterion;
import javax.media.j3d.WakeupOnAWTEvent;
import javax.media.j3d.WakeupOnBehaviorPost;
import javax.media.j3d.WakeupOr;

import net.rim.adapter.java3d.SceneObjectImpl;

import com.sun.j3d.internal.J3dUtilsI18N;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public abstract class MouseBehavior extends Behavior 
		implements MouseListener, MouseMotionListener, MouseWheelListener {

    protected boolean listener = false;
    protected WakeupCriterion[] mouseEvents;
    protected WakeupOr mouseCriterion;
    protected int x, y;
    protected int x_last, y_last;
    protected SceneObjectImpl transformGroup;
    protected Transform3D transformX;
    protected Transform3D transformY;
    protected Transform3D currXform;
    protected boolean buttonPress = false;
    protected boolean reset = false;
    protected boolean invert = false;
    protected boolean wakeUp = false;
    protected int flags = 0;

    protected LinkedList<MouseEvent> mouseq;
    protected boolean enable = true;
    public static final int MANUAL_WAKEUP = 0x1;
    public static final int INVERT_INPUT = 0x2;
	
    protected double x_factor = .02;
    protected double y_factor = .02;
    protected double z_factor = .02;
    

	/**
	 * 
	 * @param sceneObject
	 */
    public MouseBehavior(SceneObjectImpl sceneObject) {
    	super();
    	setTransformGroup(sceneObject);
    }

	
	/**
	 * 
	 * @param format
	 */
    public MouseBehavior(int format) {
    	super();
    	flags = format;
    	currXform = new Transform3D();
    	transformX = new Transform3D();
    	transformY = new Transform3D();
    	reset = true;
    }


    /**
     * 
     * @param c
     * @param sceneObject
     */
    public MouseBehavior(Component c, SceneObjectImpl sceneObject) {
    	this(sceneObject);
    	if (c != null) {
    		c.addMouseListener(this);
    		c.addMouseMotionListener(this);
    		c.addMouseWheelListener(this);
    	}
    	listener = true;
    }
    
    
    /**
     * 
     * @param transformGroup
     */
    public void setTransformGroup(SceneObjectImpl transformGroup) {
    	// need to remove old behavior from group
    	this.transformGroup = transformGroup;
    	currXform = new Transform3D();
    	transformX = new Transform3D();
    	transformY = new Transform3D();
    	reset = true;
    }

    
    /**
     * 
     * @return
     */
    public SceneObjectImpl getTransformGroup() {
    	return transformGroup;
    }
	
    
    @Override
	public void initialize() {
		mouseEvents = new WakeupCriterion[4];

		if (!listener) {
			mouseEvents[0] = new WakeupOnAWTEvent(MouseEvent.MOUSE_DRAGGED);
			mouseEvents[1] = new WakeupOnAWTEvent(MouseEvent.MOUSE_PRESSED);
			mouseEvents[2] = new WakeupOnAWTEvent(MouseEvent.MOUSE_RELEASED);
			mouseEvents[3] = new WakeupOnAWTEvent(MouseEvent.MOUSE_WHEEL);
		}
	    else {
	    	mouseEvents[0] = new WakeupOnBehaviorPost(this,
	    						MouseEvent.MOUSE_DRAGGED);
	    	mouseEvents[1] = new WakeupOnBehaviorPost(this,
	    						MouseEvent.MOUSE_PRESSED);
	    	mouseEvents[2] = new WakeupOnBehaviorPost(this,
	    						MouseEvent.MOUSE_RELEASED);
	    	mouseEvents[3] = new WakeupOnBehaviorPost(this,
	    						MouseEvent.MOUSE_WHEEL);
	    	mouseq = new LinkedList<MouseEvent>();
	    }
		
		mouseCriterion = new WakeupOr(mouseEvents);
		wakeupOn (mouseCriterion);
		x = 0;
		y = 0;
		x_last = 0;
		y_last = 0;
		
    	if ((flags & INVERT_INPUT) == INVERT_INPUT) {
    		invert = true;
    		x_factor *= -1;
    		y_factor *= -1;
    		z_factor *= -1;
    	}
	}
	
    
    /**
     * 
     */
    public void wakeup() {
    	wakeUp = true;
    }

    
    /**
     * 
     * @param evt
     */
    public void processMouseEvent(MouseEvent evt) {
    	if (evt.getID()==MouseEvent.MOUSE_PRESSED) {
    		buttonPress = true;
    		return;
    	}
    	else if (evt.getID()==MouseEvent.MOUSE_RELEASED){
    		buttonPress = false;
    		wakeUp = false;
    	}    
    }
    

    @SuppressWarnings("rawtypes")
	@Override
	public void processStimulus(Enumeration criteria) {
		// TODO Auto-generated method stub
    	WakeupCriterion wakeup;
    	AWTEvent[] events;
    	MouseEvent evt;
    	while (criteria.hasMoreElements()) {
    		wakeup = (WakeupCriterion) criteria.nextElement();
    		if (wakeup instanceof WakeupOnAWTEvent) {
    			events = ((WakeupOnAWTEvent)wakeup).getAWTEvent();
    			if (events.length > 0) {
    				evt = (MouseEvent) events[events.length-1];
    				doProcess(evt);
    			}
    		}

    		else if (wakeup instanceof WakeupOnBehaviorPost) {
    			while (true) {
    				// access to the queue must be synchronized
    				synchronized (mouseq) {
    					if (mouseq.isEmpty()) break;
    					evt = (MouseEvent)mouseq.remove(0);
    					// consolidate MOUSE_DRAG events
    					while ((evt.getID() == MouseEvent.MOUSE_DRAGGED) &&
    							!mouseq.isEmpty() &&
    							(((MouseEvent)mouseq.get(0)).getID() ==
    							MouseEvent.MOUSE_DRAGGED)) {
    						
    						evt = (MouseEvent)mouseq.remove(0);
    					}
    				}
    				doProcess(evt);
    			}
    		}

    	}
    	wakeupOn (mouseCriterion);
	}

	
	
	/**
	 * 
	 * @param evt
	 */
    protected abstract void doProcess(MouseEvent evt);
	
	
    /**
     * 
     * @param c
     */
    public void addListener(Component c) {
    	if (!listener) {
    		throw new IllegalStateException(J3dUtilsI18N.getString("Behavior0"));
    	}
    	c.addMouseListener(this);
    	c.addMouseMotionListener(this);
    	c.addMouseWheelListener(this);
    }

    
    @Override
    public void mouseClicked(MouseEvent e) {}
    
    @Override
    public void mouseEntered(MouseEvent e) {}
    
    @Override
    public void mouseExited(MouseEvent e) {}

    
    @Override
    public void mousePressed(MouseEvent e) {
    	//   	System.out.println("mousePressed");

    	// add new event to the queue
    	// must be MT safe
    	if (enable) {
    		synchronized (mouseq) {
    			mouseq.add(e);
    			// only need to post if this is the only event in the queue
    			if (mouseq.size() == 1) 
    				postId(MouseEvent.MOUSE_PRESSED);
    		}
    	}
    }

    
    @Override
    public void mouseReleased(MouseEvent e) {
    	//   	System.out.println("mouseReleased");

    	// add new event to the queue
    	// must be MT safe
    	if (enable) {
    		synchronized (mouseq) {
    			mouseq.add(e);
    			// only need to post if this is the only event in the queue
    			if (mouseq.size() == 1)
    				postId(MouseEvent.MOUSE_RELEASED);
    		}
    	}
    }


    @Override
    public void mouseDragged(MouseEvent e) {
    	//   	System.out.println("mouseDragged");

    	// add new event to the to the queue
    	// must be MT safe.
    	if (enable) {
    		synchronized (mouseq) {
    			mouseq.add(e);
    			// only need to post if this is the only event in the queue
    			if (mouseq.size() == 1) 
    				postId(MouseEvent.MOUSE_DRAGGED);
    		}
    	}
    }

    
    @Override
    public void mouseMoved(MouseEvent e) {}

    
    @Override
    public void setEnable(boolean state) {
    	super.setEnable(state);
    	this.enable = state;
    	if (!enable && (mouseq != null)) {
    		mouseq.clear();
    	}
    }

    
    @Override
    public void mouseWheelMoved(MouseWheelEvent e){
    	System.out.println("MouseBehavior : mouseWheel enable = " + enable );
  	
    	// add new event to the to the queue
    	// must be MT safe.
    	if (enable) {
    		synchronized (mouseq) {
    			mouseq.add(e);
    			// only need to post if this is the only event in the queue
    			if (mouseq.size() == 1) 
    				postId(MouseEvent.MOUSE_WHEEL);
    		}
    	}
    }
    
    
}
