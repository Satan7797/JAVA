package program27;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

@SuppressWarnings("serial")
public class MouseEventDemo extends Applet implements MouseListener,MouseMotionListener {
	String msg=" ";
	int mouseX=0,mouseY=0;
	
	public MouseEventDemo() {
		addMouseListener(this);
		addMouseMotionListener(this);
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
		msg="*"+" mouse at "+mouseX+", "+mouseY;
		repaint();
	}
	
	public void mouseMoved(MouseEvent me) {
		msg="Moving mouse at "+me.getX()+", "+me.getY();
		repaint();
	}
	
	public void paint(Graphics g) {
		g.drawString(msg, mouseX, mouseY);
	}
}
