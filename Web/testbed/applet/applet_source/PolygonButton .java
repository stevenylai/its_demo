import java.awt.Color;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Polygon;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionAdapter;
import java.awt.event.MouseMotionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

import javax.swing.JApplet;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JToolTip;
import javax.swing.Timer;

class PolygonButton extends JComponent implements MouseListener,
    MouseMotionListener {
  static public Color ACTIVE_COLOR = Color.red;

  static public Color INACTIVE_COLOR = Color.darkGray;

  protected String text;

  protected Polygon polygon;

  protected Rectangle rectangle;

  protected boolean isActive;

  protected static PolygonButton button;

  public PolygonButton(Polygon p, String text) {
    polygon = p;
    setText(text);

    setOpaque(false);

    addMouseListener(this);
    addMouseMotionListener(this);

    rectangle = new Rectangle(polygon.getBounds()); // Bug alert!
    rectangle.grow(1, 1);

    setBounds(rectangle);
    polygon.translate(-rectangle.x, -rectangle.y);
  }

  public void setText(String t) {
    text = t;
  }

  public String getText() {
    return text;
  }

  public void mouseMoved(MouseEvent e) {
    if (!rectangle.contains(e.getX(), e.getY()) || e.isConsumed()) {
      if (isActive) {
        isActive = false;
        repaint();
      }
      return; // quickly return, if outside our rectangle
    }

    int x = e.getX() - rectangle.x;
    int y = e.getY() - rectangle.y;
    boolean active = polygon.contains(x, y);

    if (isActive != active)
      setState(active);
    if (active)
      e.consume();
  }

  public void mouseDragged(MouseEvent e) {
  }

  protected void setState(boolean active) {
    isActive = active;
    repaint();
    if (active) {
      if (button != null)
        button.setState(false);
      setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
    } else {
      button = null;
      setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR));
    }
  }

  public void mouseClicked(MouseEvent e) {
  }

  public void mousePressed(MouseEvent e) {
  }

  public void mouseReleased(MouseEvent e) {
  }

  public void mouseExited(MouseEvent e) {
    mouseMoved(e);
  }

  public void mouseEntered(MouseEvent e) {
    mouseMoved(e);
  }

  public void paint(Graphics g) {
    g.setColor(isActive ? ACTIVE_COLOR : INACTIVE_COLOR);
    g.drawPolygon(polygon);
  }
  public static void main(String[] argv) {
    JFrame f = new JFrame();
    f.setSize(400, 300);
    Polygon p = new Polygon();
    p.addPoint(10, 10);
    p.addPoint(100, 300);
    p.addPoint(300, 300);
    p.addPoint(10, 10);

    PolygonButton btn = new PolygonButton(p, "button");
    f.getContentPane().add(btn);
    WindowListener wndCloser = new WindowAdapter() {
      public void windowClosing(WindowEvent e) {
        System.exit(0);
      }
    };
    f.addWindowListener(wndCloser);
    f.setVisible(true);
  }
}
