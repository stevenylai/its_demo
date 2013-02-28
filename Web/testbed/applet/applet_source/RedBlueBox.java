import java.awt.Color;
import java.awt.Container;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.Polygon;

import javax.swing.BorderFactory;
import javax.swing.JComponent;
import javax.swing.JFrame;

class RedBlueBox extends JComponent {

  public void paintComponent(Graphics g) {
    Insets insets = getInsets();
    int endX = getWidth() - insets.right;
    int endY = getHeight() - insets.bottom;
    // get the top-left corner
    int x = insets.left;
    int y = insets.top;

    g.setColor(Color.RED);
    Polygon p = new Polygon();
    p.addPoint(x, y);
    p.addPoint(endX, y);
    p.addPoint(x, endY);
    g.fillPolygon(p);
    g.setColor(Color.BLUE);
    p.reset();
    p.addPoint(endX, y);
    p.addPoint(x, endY);
    p.addPoint(endX, endY);
    g.fillPolygon(p);
  }

  public static void main(String args[]) {
    JFrame frame = new JFrame();
    Container contentPane = frame.getContentPane();
    contentPane.setLayout(new GridLayout(0, 1));
    JComponent comp = new RedBlueBox();
    comp.setBorder(BorderFactory.createMatteBorder(5, 5, 5, 5, Color.PINK));
    contentPane.add(comp);
    comp = new RedBlueBox();
    contentPane.add(comp);
    frame.setSize(300, 200);
    frame.show();
  }

}