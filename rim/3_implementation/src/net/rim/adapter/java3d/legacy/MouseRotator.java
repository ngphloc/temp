/**
 * Source repository: Java 3D
 * Class URL: com.sun.j3d.utils.picking.behaviors.PickRotateBehavior
 * 
 */

package net.rim.adapter.java3d.legacy;

import java.awt.event.MouseEvent;

import javax.vecmath.Matrix4d;
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
public class MouseRotator extends MouseBehavior {
	
	/**
	 * 
	 */
    protected double x_angle = 0;
    
    
    /**
     * 
     */
    protected double y_angle = 0;
    
    
    /**
     * 
     */
    protected double z_angle = 0;

    
	/**
	 * 
	 */
	public MouseRotator() {
		super(0);
		// TODO Auto-generated constructor stub
	}

	
	/**
	 * 
	 * @param flags
	 */
	public MouseRotator(int flags) {
		super(flags);
		// TODO Auto-generated constructor stub
	}

	
	/**
	 * 
	 * @param sceneObject
	 */
	public MouseRotator(SceneObjectImpl sceneObject) {
		super(sceneObject);
		// TODO Auto-generated constructor stub
	}

	
	@Override
    protected void doProcess(MouseEvent evt) {
    	if (transformGroup instanceof LinkView)
        	doProcessLinkView(evt);
    	else
    		doProcessNormal(evt);
    }
    
    
	/**
	 * 
	 * @param evt
	 */
	protected void doProcessLinkView(MouseEvent evt) {
    	LinkView linkView = (LinkView)transformGroup;
    	if (!linkView.isMoveable() || linkView.getJointType() != JointType.rot)
    		return;
		
    	processMouseEvent(evt);
    	boolean condition = ((buttonPress)&&((flags & MANUAL_WAKEUP) == 0)) ||
    			((wakeUp)&&((flags & MANUAL_WAKEUP) != 0));
    	if (!condition)
    		return;
    	
		int id = evt.getID();
		if ((id == MouseEvent.MOUSE_DRAGGED) && 
				!evt.isMetaDown() && !evt.isAltDown()) {
			x = evt.getX();
			y = evt.getY();
	
			int dx = x - x_last;
	
			if (!reset) {	    
				z_angle = dx * z_factor;
				double variable = linkView.getKineticParam();
				double fixValue = linkView.getConstraint().fixValue(variable + z_angle);
				z_angle = fixValue - variable; 
				
				transformX.rotZ(z_angle);
	    
				linkView.getTransform(currXform);
	    
				Matrix4d mat = new Matrix4d();
				// Remember old matrix
				currXform.get(mat);
	    
				// Translate to origin
				currXform.setTranslation(new Vector3d(0.0,0.0,0.0));
				if (invert)
					currXform.mul(currXform, transformX);
				else
					currXform.mul(transformX, currXform);
	    
				// Set old translation back
				Vector3d translation = new 
						Vector3d(mat.m03, mat.m13, mat.m23);
				currXform.setTranslation(translation);
	    
				// Update xform
				linkView.setTransform(currXform, false);
				linkView.setKineticParam(variable + z_angle);
				
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
				!evt.isMetaDown() && !evt.isAltDown()) {
			x = evt.getX();
			y = evt.getY();
	
			int dx = x - x_last;
			int dy = y - y_last;
	
			if (!reset) {	    
				x_angle = dy * y_factor;
				y_angle = dx * x_factor;
	    
				transformX.rotX(x_angle);
				transformY.rotY(y_angle);
	    
				transformGroup.getTransform(currXform);
	    
				Matrix4d mat = new Matrix4d();
				// Remember old matrix
				currXform.get(mat);
	    
				// Translate to origin
				currXform.setTranslation(new Vector3d(0.0,0.0,0.0));
				if (invert) {
					currXform.mul(currXform, transformX);
					currXform.mul(currXform, transformY);
				} 
				else {
					currXform.mul(transformX, currXform);
					currXform.mul(transformY, currXform);
				}
	    
				// Set old translation back
				Vector3d translation = new 
						Vector3d(mat.m03, mat.m13, mat.m23);
				currXform.setTranslation(translation);
	    
				// Update xform
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
