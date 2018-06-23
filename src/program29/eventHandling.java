package program29;

import java.awt.*;
import java.awt.event.*;

class MyWindowAdapter extends WindowAdapter{
   public void windowClosing(WindowEvent e){
      System.exit(0);
   }
}
public class eventHandling extends Frame implements MouseListener, MouseMotionListener, KeyListener {
	
	private static final long serialVersionUID = 1L;
	String msg="",keyStats="";
	int mouseX,mouseY;
	int x=100,y=100;
	
	public eventHandling() {
		addMouseMotionListener(this);
		addMouseListener(this);
		addKeyListener(this);
		addWindowListener(new MyWindowAdapter());
	}
	
	public void mouseClicked(MouseEvent me) {
		msg=msg+" --click received";
		repaint();
	}
	
	public void mouseEntered(MouseEvent me) {
		mouseX=100;
		mouseY=100;
		msg="Mouse Entered";
		repaint();
	}
	
	public void mouseExited(MouseEvent me) {
		mouseX=100;
		mouseY=100;
		msg="Mouse exited";
		repaint();
	}
	public void mousePressed(MouseEvent me) {
		mouseX=me.getX();
		mouseY=me.getY();
		msg="Button down";
		repaint();
	}
	
	public void mouseReleased(MouseEvent me) {
		mouseX=me.getX();
		mouseY=me.getY();
		msg="Button released";
		repaint();
	}
	public void mouseDragged(MouseEvent me) {
		mouseX=me.getX();
		mouseY=me.getY();
		msg="Dragging mouse at "+mouseX+", "+mouseY;
		repaint();
	}
	
	public void mouseMoved(MouseEvent me) {
		msg="Moving mouse at "+me.getX()+", "+me.getY();
		repaint();
	}
	public void keyPressed(KeyEvent ke) {
		keyStats = "Key Down";
		int key=ke.getKeyChar();
		switch(key) {
		case KeyEvent.VK_KP_UP:
			msg+="UP Key";
			break;
		case KeyEvent.VK_LEFT:
			msg+="Left key";
			break;
		}
		repaint();
	}

	public void keyReleased(KeyEvent ke) {
		keyStats = "Key up";
		repaint();
	}

	public void keyTyped(KeyEvent e) {
		if (e.getKeyChar() == '\b')
			msg = msg.substring(0, msg.length() - 1);
		else
			msg += e.getKeyChar();
		if(e.getKeyChar()=='\n')
			y++;
		repaint();
	}

	
	public void paint(Graphics g) {
		g.drawString(msg, x, y);
		g.drawString(keyStats, 20, 50);
	}
	public static void main(String[] args) {
		eventHandling e=new eventHandling();
		e.setVisible(true);
		e.setSize(500,500);
		e.setTitle("Event Handling");
	}
}
