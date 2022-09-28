package net.rim.adapter.java3d.legacy;

import java.awt.event.MouseEvent;

import javax.vecmath.Vector3d;

import net.rim.adapter.java3d.LinkView;
import net.rim.adapter.java3d.SceneObjectImpl;
import net.rim.core.KineticParam.JointType;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class MouseTranslater extends MouseBehavior {
	
	/**
	 * 
	 */
    protected Vector3d translation = new Vector3d();

    
	/**
	 * 
	 */
	public MouseTranslater() {
		super(0);
		// TODO Auto-generated constructor stub
	}

	
	/**
	 * 
	 * @param flags
	 */
	public MouseTranslater(int flags) {
		super(flags);
		// TODO Auto-generated constructor stub
	}

	
	/**
	 * 
	 * @param sceneObject
	 */
	public MouseTranslater(SceneObjectImpl sceneObject) {
		super(sceneObject);
		// TODO Auto-generated constructor stub
	}

	
    /**
     * 
     * @param evt
     */
    protected void doProcess(MouseEvent evt) {
    	if (transformGroup instanceof LinkView) {
        	doProcessLinkView(evt);
    	}
    	else
    		doProcessNormal(evt);

    }
    
    
	/**
	 * 
	 * @param evt
	 */
	protected void doProcessLinkView(MouseEvent evt) {
    	LinkView linkView = (LinkView)transformGroup;
    	if (!linkView.isMoveable() || linkView.getJointType() != JointType.trans)
    		return;
    	
    	processMouseEvent(evt);
    	boolean condition = ((buttonPress)&&((flags & MANUAL_WAKEUP) == 0)) ||
    			((wakeUp)&&((flags & MANUAL_WAKEUP) != 0));
    	if (!condition)
    		return;
    	
		int id = evt.getID();
		if ((id == MouseEvent.MOUSE_DRAGGED) && 
				evt.isMetaDown() && !evt.isAltDown()) {
			x = evt.getX();
			y = evt.getY();
			
			int dy = y - y_last;
			
			if ( (!reset) && ((Math.abs(dy) < 50)) ) {
			    //System.out.println("dx " + dx + " dy " + dy);
				
				translation.set(0, 0, 0);
			    translation.z = dy * z_factor;
			    	
				double variable = linkView.getKineticParam();
				double fixValue = linkView.getConstraint().fixValue(variable + translation.z);
				translation.z = fixValue - variable; 
				
			    linkView.getTransform(currXform);
			    transformX.set(translation);
			    
			    if (invert)
			    	currXform.mul(currXform, transformX);
			    else
			    	currXform.mul(transformX, currXform);
			    
			    linkView.setTransform(currXform, false);
			    linkView.setKineticParam(variable + translation.z);
				    
			}
			else {
			    reset = false;
			}
	
			x_last = x;
			y_last = y;
		}
		else if (id == MouseEvent.MOUSE_PRESSED) {
			x_last = evt.getX();
			y_last = evt.getY();
		}
	}
	
	
    /**
     * 
     * @param evt
     */
    protected void doProcessNormal(MouseEvent evt) {

    	processMouseEvent(evt);
    	boolean condition = ((buttonPress)&&((flags & MANUAL_WAKEUP) == 0)) ||
    			((wakeUp)&&((flags & MANUAL_WAKEUP) != 0));
    	if (!condition)
    		return;

		int id = evt.getID();
		if ((id == MouseEvent.MOUSE_DRAGGED) && 
				evt.isMetaDown() && !evt.isAltDown()) {
			x = evt.getX();
			y = evt.getY();
			
			int dx = x - x_last;
			int dy = y - y_last;
			
			if ((!reset) && ((Math.abs(dy) < 50) && (Math.abs(dx) < 50))) {
			    //System.out.println("dx " + dx + " dy " + dy);
			    transformGroup.getTransform(currXform);
			    
				translation.set(0, 0, 0);
			    translation.x = dx * x_factor; 
			    translation.y = -dy * y_factor;
			    
			    transformX.set(translation);
			    
			    if (invert)
			    	currXform.mul(currXform, transformX);
			    else
			    	currXform.mul(transformX, currXform);
			    
			    transformGroup.setTransform(currXform, true);
			    
			}
			else {
			    reset = false;
			}
	
			x_last = x;
			y_last = y;
		}
		else if (id == MouseEvent.MOUSE_PRESSED) {
			x_last = evt.getX();
			y_last = evt.getY();
		}
    	
    	
    }
    
    
    
    
}
