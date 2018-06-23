package program25;

import java.applet.*;
import java.awt.*;
import java.util.Random;

@SuppressWarnings("serial")
public class AppletDemo extends Applet implements Runnable {
	
	Thread t;
	String msg="This is a test.";

	public void init() {
		setBackground(Color.BLACK);
		setForeground(Color.WHITE);
	}

	public void start() {
		t=new Thread(this);
		t.start();
	}
	
	public void run() {
		for(; ;) {
			try {
				repaint();
				Thread.sleep(500);
			}
			catch(InterruptedException e) {
				System.out.println("Exception caught");
			}
		}
	}
	
	public void paint(Graphics g) {
		char ch;
		ch = msg.charAt(0);
		msg = msg.substring(1, msg.length());
		msg += ch;
		g.drawString(msg,150,23);
	}

}
