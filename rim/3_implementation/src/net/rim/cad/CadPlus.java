package net.rim.cad;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JPanel;
import javax.vecmath.Vector3d;

import net.rim.Sys;
import net.rim.adapter.java3d.LinkMuscleImpl;
import net.rim.adapter.java3d.RobotView;
import net.rim.core.KineticParam.JointType;
import net.rim.core.KineticParamList;
import net.rim.core.Link;
import net.rim.core.Robot;
import net.rim.core.Scene;
import net.rim.core.ViewParam;
import net.rim.core.ViewParam.Mode;

import com.sun.j3d.utils.geometry.ColorCube;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class CadPlus extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	
	/**
	 * 
	 */
	private Scene scene = null;
	
	
	/**
	 * 
	 */
	public CadPlus() {
		super("Rim CAD");
		scene = Sys.AdapterFactory.createScene();
		
		initUI();
		
		test();
	}
	
	
	/**
	 * 
	 */
	private void initUI() {
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setSize(800, 600);
		setJMenuBar(createMenuBar());
		addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosed(WindowEvent e) {
				// TODO Auto-generated method stub
				onClosed();
			}
		});
		
		Container content = getContentPane();
		content.setLayout(new BorderLayout(4, 4));

		content.add(createHeader(), BorderLayout.NORTH);
		content.add(createBody(), BorderLayout.CENTER);
		content.add(createFooter(), BorderLayout.SOUTH);
	}
	
	
	/**
	 * 
	 * @return
	 */
	private JMenuBar createMenuBar() {
		JMenuBar mnBar = new JMenuBar();
		return mnBar;
	}
	
	
	/**
	 * 
	 * @return
	 */
	private JPanel createHeader() {
		JPanel main = new JPanel(new BorderLayout());
		return main;
	}
	
	
	/**
	 * 
	 * @return
	 */
	private JPanel createBody() {
		JPanel main = new JPanel(new BorderLayout());
		
		JPanel body = new JPanel(new BorderLayout());
		main.add(body, BorderLayout.CENTER);
		body.add(scene.getCanvas());
		return main;
	}

	
	/**
	 * 
	 * @return
	 */
	private JPanel createFooter() {
		JPanel main = new JPanel(new BorderLayout());
		return main;
	}

	
	/**
	 * 
	 */
	private void onClosed() {
		if (scene != null)
			scene.cleanup();
		System.exit(0);
	}
	
	
	private void test() {
		KineticParamList paramList = new KineticParamList();
		paramList.add(0.1);
		paramList.add(JointType.rot, 0, -Math.PI / 2, 0.2, 0);
		paramList.add(JointType.rot, 0, Math.PI / 2, 0.3, 0);
		paramList.add(JointType.trans, 0, 0, 0.2, 0);
		
		paramList.add(JointType.rot, 0, -Math.PI / 2, 0.2, 0);
		
		paramList.add(JointType.rot, 0, Math.PI / 2, 0.1, 0);
		paramList.add(JointType.rot, 0, 0, 0.2, 0);
		
		Robot robot = Sys.AdapterFactory.createRobot(paramList);
		int n = robot.getLinkCount();
		for (int i = 0; i < n; i++) {
			Link link = robot.getLink(i);
			LinkMuscleImpl muscle = new LinkMuscleImpl(link, false);
			muscle.setShape(new ColorCube(0.02));
			muscle.translate(new Vector3d(0, 0, 0.01), true);
			link.addMuscle(muscle);
		}
		
		
		scene.addSceneObject(new RobotView(robot, new ViewParam(Mode.body, 0)));
	}
	
	
}
