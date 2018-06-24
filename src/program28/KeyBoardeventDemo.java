/*Write a program to demonstrate different keyboard handling events.*/

package program28;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;


public class KeyBoardeventDemo extends Applet implements KeyListener {

	String msg = "";
	String keyStats = "";
	int x=20,y=100;

	public void init() {
		addKeyListener(this);
	}

	public void keyPressed(KeyEvent ke) {
		keyStats = "Key Down";
		int key=ke.getKeyChar();
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
}
