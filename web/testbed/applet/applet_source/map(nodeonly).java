import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.util.Vector; 
import java.awt.image.*;   

public class map extends Applet
implements MouseListener, MouseMotionListener 
{
	
	private int width, height;
	private int mx, my;  // the mouse coordinates
	private boolean isButtonPressed = false;
	//private Button   button; 
	private Image img_map; 
	private Image[] img_tool = new Image[6];
	private Image[] img_cursor = new Image[3];
    private URL base;
    private MediaTracker mt;
	private int toolselected = 0;
	//private int nodeover = -1;
	Vector nodeover  = new Vector();
	private int submenux=-1, submenuy=-1;
	private boolean showRect = false;
	private boolean showLine = false;
	private int presssx=-1, presssy=-1;
	private int pressex=-1, pressey=-1;
	Vector vnodes = new Vector();
	Vector nodeselected  = new Vector();
	//private int no_node = 10;
	//private nodes[] n = new nodes[no_node];
	private Graphics g = getGraphics();
	private int action = 0;
	Graphics bufferGraphics; 
    Image offscreen;
     
	public void init() 
	{
		
		vnodes.addElement(new node(1,24,40));
		vnodes.addElement(new node(2,24,75));
		((node)vnodes.get(1)).setStatus(2);
		vnodes.addElement(new node(3,24,118));
		((node)vnodes.get(2)).setStatus(2);
		vnodes.addElement(new node(4,24,208));
		vnodes.addElement(new node(24,45,15));
		vnodes.addElement(new node(34,45,82));
		vnodes.addElement(new node(33,45,100));
		vnodes.addElement(new node(32,215,82));
		vnodes.addElement(new node(31,215,100));
		vnodes.addElement(new node(28,145,15));
		vnodes.addElement(new node(27,187,17));
		vnodes.addElement(new node(26,230,17));
		vnodes.addElement(new node(64,162,34));
		vnodes.addElement(new node(65,180,34));
		vnodes.addElement(new node(66,162,181));
		vnodes.addElement(new node(67,180,181));
		//nodeselected.clear();
		
		width = getSize().width;
		height = getSize().height;

		setBackground(new Color(129,228,243));
		
		mx = width/2;
		my = height/2;
		
		offscreen = createImage(700,500); 
		//offscreen = createImage(dim.width,dim.height); 
		bufferGraphics = offscreen.getGraphics();
		
		mt = new MediaTracker(this);
		try 
		{ 
				// getDocumentbase gets the applet path. 
			base = getDocumentBase(); 
        } 
        catch (Exception e) 
        {
			System.out.println("Error : getDocumentBase");
        }

		  // Here we load the image. 
		  // Only Gif and JPG are allowed. Transparant gif also. 
          img_map = getImage(base,"map.jpg");
		  img_tool[0] = getImage(base,"tool1.gif");
		  img_tool[1] = getImage(base,"tool2.gif");
		  img_tool[2] = getImage(base,"tool3.gif");
		  img_tool[3] = getImage(base,"tool1_click.gif");
		  img_tool[4] = getImage(base,"tool2_click.gif");
		  img_tool[5] = getImage(base,"tool3_click.gif");
		  
		  img_cursor[0] = getImage(base,"ctool1.gif");
		  img_cursor[1] = getImage(base,"ctool2.gif");
		  img_cursor[2] = getImage(base,"ctool3.gif");
		  // tell the MediaTracker to kep an eye on this image, and give it ID 1; 
          mt.addImage(img_map,1);
		  mt.addImage(img_tool[0],2);
		  mt.addImage(img_tool[1],3);
		  mt.addImage(img_tool[2],4);
		  mt.addImage(img_tool[3],5);
		  mt.addImage(img_tool[4],6);
		  mt.addImage(img_tool[5],7);
		  mt.addImage(img_cursor[0],8);
		  mt.addImage(img_cursor[1],9);
		  mt.addImage(img_cursor[2],10);

		  
		  // now tell the mediaTracker to stop the applet execution 
		  // (in this example don't paint) until the images are fully loaded. 
		  // must be in a try catch block.
         try 
         { 
			mt.waitForAll(); 
         } 
         catch (InterruptedException  e) 
         {
			System.out.println("Error : waitForAll");
         }
          
        Cursor cursor = createCustomCursor(img_cursor[0],new Point(0,0),"cursor",this);     
		setCursor(cursor);  
		addMouseListener( this );
		addMouseMotionListener( this );
		System.out.println("1e");
	}
	
	public void mouseEntered( MouseEvent e ) 
	{
	// called when the pointer enters the applet's rectangular area
	}
	public void mouseExited( MouseEvent e ) 
	{
	// called when the pointer leaves the applet's rectangular area
	}
	public void mouseClicked( MouseEvent e ) 
	{
		e.consume();
		//System.out.println("mouseClicked");
		
	}
	public void mousePressed( MouseEvent e ) 
	{  // called after a button is pressed down
	//	System.out.println("3s");
	// called after a press and release of a mouse button
	// with no motion in between
	// (If the user presses, drags, and then releases, there will be
	// no click event generated.)
		isButtonPressed = true;
		switch(toolselected)
		{
			case 0:case 1:
				presssx = e.getX();
				presssy = e.getY();
				break;
		}
		e.consume();
		//System.out.println("mousePressed");
	}
	public void mouseReleased( MouseEvent e ) 
	{  // called after a button is released
		isButtonPressed = false;
		/*setBackground( Color.gray );
		repaint();
		e.consume();*/
		
		mx = e.getX();
		my = e.getY();
		//System.out.println("X:"+(mx-(int)(width*0.16))+",Y:"+(my-(int)(height*0.03)));
		//System.out.println("Mouse at (" + mx + "," + my + ")");
		

		switch(action)
		{
			case 0:
				//tool
				for(int i = 0 ; i < 3 ; i ++)
				{
					if(mx > (int)(width*0.05) && mx < (int)(width*0.05)+40 && my > (int)(height*0.4)+(40*i) && my < (int)(height*0.4)+40+(40*i))
					{
						toolselected = i;
						repaint();
						Cursor cursor = createCustomCursor(img_cursor[i],new Point(0,0),"cursor",this);     
						setCursor(cursor);
						break;
					}
				}
				
				if(toolselected == 0)
				{
					//sensor
					if(!showRect)
					{
						for(int i = 0;i < vnodes.size();i++)
						{
							int tempx = ((node)vnodes.get(i)).getx();
							int tempy = ((node)vnodes.get(i)).gety();
							if(mx > (int)(width*0.16)+tempx && mx < (int)(width*0.16)+tempx+14 && my > (int)(height*0.03)+tempy && my < (int)(height*0.03)+tempy+14)
							{
								nodeselected.addElement(vnodes.get(i));
								submenux=mx; submenuy= my;
								action = 1;
								
								break;
							}
						}
					}
					else
					{
						//System.out.println(showRect);
						for(int i = 0;i < vnodes.size();i++)
						{
							int tempx = ((node)vnodes.get(i)).getx();
							int tempy = ((node)vnodes.get(i)).gety();
							
							int sx  ; int ex ;
							int sy  ; int ey ;
							if(presssx>pressex)
							{
								sx=pressex;
								ex=presssx;
							}
							else
							{
								sx=presssx;
								ex=pressex;
							}
							if(presssy>pressey)
							{
								sy=pressey;
								ey=presssy;
							}
							else
							{
								sy=presssy;
								ey=pressey;
							}
							//System.out.println("sx:"+sx+", ex:"+ex+", sy:"+sy+", ey:"+ey);
							//System.out.println("sx:"+((int)(width*0.16)+tempx)+", ex:"+((int)(width*0.16)+tempx+14)+", sy:"+((int)(height*0.03)+tempy )+", ey:"+((int)(height*0.03)+tempy+14));
							if(sx < (int)(width*0.16)+tempx && ex > (int)(width*0.16)+tempx+14 && sy < (int)(height*0.03)+tempy && ey > (int)(height*0.03)+tempy+14)
							{
							//	System.out.println("i:"+i);
								action = 1;
								submenux=mx; submenuy= my;
								nodeselected.addElement(vnodes.get(i));
								//break;
							}
						}
					}
				}
				repaint();
				break;
				
			  case 1://submenu
				if(toolselected == 0)
				{
					if(mx > submenux+10 && mx < submenux+100 && my > submenuy+10 && my < submenuy+132)
					{
						if(mx > submenux+10 && mx < submenux+100 && my > submenuy+10 && my < submenuy+42)
						{
							//System.out.println("ac : "+nodeselected+"\n");
							//int temp = nodeselected.get(1));
							for(int i = 0 ; i< nodeselected.size();i++)	
								((node)nodeselected.get(i)).setStatus(1);	
						}
						else if(mx > submenux+10 && mx < submenux+100 && my > submenuy+42 && my < submenuy+72)
						{
							//System.out.println("de : "+nodeselected);
							//int temp = (int)(nodeselected.get(1));
							for(int i = 0 ; i< nodeselected.size();i++)		
								((node)nodeselected.get(i)).setStatus(2);
						}
						else if(mx > submenux+10 && mx < submenux+100 && my > submenuy+72 && my < submenuy+102)
						{		
							//System.out.println("Upload");
							action = 1;
						}	
						else if(mx > submenux+10 && mx < submenux+100 && my > submenuy+102 && my < submenuy+132)
						{
							//System.out.println("information");
							action = 1;
						}
						///repaint();
					}
					nodeselected.clear();
					nodeover.clear();
					action = 0;
					repaint();
				}
				break;
		}
		showRect = false;
		showLine = false;
		g.setColor( new Color(220,220,220) );
		g.fillRect( (int)(width*0.16), (int)(height*0.03), 528, 437 );
		g.drawImage(img_map,(int)(width*0.16)+5,(int)(height*0.03)+5,this);
		repaint();
		presssx = -1;
		presssy = -1;
		pressex = -1; 
		pressey = -1;
		
		e.consume();
		//System.out.println("mouseReleased");
	}
	public void mouseMoved( MouseEvent e ) 
	{  // called during motion when no buttons are down
		mx = e.getX();
		my = e.getY();		
		nodeover.clear();
		switch(toolselected)
		{
			case 0:
				switch(action)
				{
					case 0:
						//sensor
						for(int i = 0;i < vnodes.size();i++)
						{
							int tempx = ((node)vnodes.get(i)).getx();
							int tempy = ((node)vnodes.get(i)).gety();
							if(mx > (int)(width*0.16)+tempx && mx < (int)(width*0.16)+tempx+14 && my > (int)(height*0.03)+tempy && my < (int)(height*0.03)+tempy+14)
							{
								nodeover.addElement(vnodes.get(i));
								break;
							}
						}
						repaint();
						break;
				}
				break;
			case 1:
				switch(action)
				{
					case 0:
						//sensor
						for(int i = 0;i < vnodes.size();i++)
						{
							int tempx = ((node)vnodes.get(i)).getx();
							int tempy = ((node)vnodes.get(i)).gety();
							if(mx > (int)(width*0.16)+tempx && mx < (int)(width*0.16)+tempx+14 && my > (int)(height*0.03)+tempy && my < (int)(height*0.03)+tempy+14)
							{
								nodeover.addElement(vnodes.get(i));
							}
						}
						repaint();
						break;
				}
				break;
		}		
		e.consume();
	}
	public void mouseDragged( MouseEvent e ) 
	{  // called during motion with buttons down
		mx = e.getX();
		my = e.getY();
		
		//System.out.print("Mouse at (" + mx + "," + my + ")");
		//showStatus( "mouseDragged at (" + mx + "," + my + ")" );
		switch(toolselected)
		{
			case 0: 
				switch(action)
				{
					case 0:
						if(isButtonPressed)
						{
							pressex = mx; 
							pressey = my;
							showRect = true;
							//System.out.print("multi select");
							repaint();
						}	
						break;
				}
				break;
			case 1:
				switch(action)
				{
					case 0:
						
						//sensor
						for(int i = 0;i < vnodes.size();i++)
						{
							int tempx = ((node)vnodes.get(i)).getx();
							int tempy = ((node)vnodes.get(i)).gety();
							if(mx > (int)(width*0.16)+tempx && mx < (int)(width*0.16)+tempx+14 && my > (int)(height*0.03)+tempy && my < (int)(height*0.03)+tempy+14)
							{
								nodeover.addElement(vnodes.get(i));
							}
						}
						if(isButtonPressed)
						{
							pressex = mx; 
							pressey = my;
							showLine = true;
							//System.out.print("multi select");
							//repaint();
						}	
						
						repaint();
						break;
				}
				
		}
		e.consume();
		//System.out.println("mouseDragged");
	}
	
	public void paint( Graphics g ) 
	{
		//System.out.println("paint");
		//Background
		bufferGraphics.setColor(new Color(129,228,243));
		bufferGraphics.fillRect( 0, 0, width, height );
		
		//map area
		bufferGraphics.setColor( new Color(220,220,220) );
		bufferGraphics.fillRect( (int)(width*0.16), (int)(height*0.03), 528, 437 );
		bufferGraphics.drawImage(img_map,(int)(width*0.16)+5,(int)(height*0.03)+5,this);
		//bufferGraphics.drawImage(img_map,0,0,this);

		//System.out.println("Size:"+nodeselected.size());
		
		//toolbox
		bufferGraphics.setColor( new Color(220,220,220) );
		bufferGraphics.fillRect( (int)(width*0.05), (int)(height*0.4), 45, 130 );
		for (int i = 0 ; i < 3; i++)
		{
			if(toolselected == i)
				bufferGraphics.drawImage(img_tool[i+3],(int)(width*0.05),(int)(height*0.4)+(42*i),this);
			else
				bufferGraphics.drawImage(img_tool[i],(int)(width*0.05),(int)(height*0.4)+(42*i),this);
		}
		
		//sensor
		for(int i = 0;i < vnodes.size();i++)
		{
			int tempx = ((node)vnodes.get(i)).getx();
			int tempy = ((node)vnodes.get(i)).gety();
			
			if((action== 0||action==1)&&(nodeselected.indexOf(vnodes.get(i))!=-1||nodeover.indexOf(vnodes.get(i))!=-1))
				bufferGraphics.setColor(Color.ORANGE);
			else
				bufferGraphics.setColor(new Color(0,0,0));
			bufferGraphics.drawRect( (int)(width*0.16)+tempx, (int)(height*0.03)+tempy,15,15 );
			bufferGraphics.drawRect( (int)(width*0.16)+tempx-1, (int)(height*0.03)+tempy-1,17,17 );
			switch (((node)vnodes.get(i)).getStatus())
			{
				case 1:
					bufferGraphics.setColor(new Color(0,255,0));
					break;
				case 2:
					bufferGraphics.setColor(new Color(225,0,0));
					break;
				case 0:default:
					bufferGraphics.setColor(new Color(220,220,220));
			}
			bufferGraphics.fillRect((int)(width*0.16)+tempx+1, (int)(height*0.03)+tempy+1,14, 14);
			
			bufferGraphics.setColor(new Color(0,0,0));
			bufferGraphics.drawString(Integer.toString(((node)vnodes.get(i)).getid()),(int)(width*0.16)+tempx+(((node)vnodes.get(i)).getid()<10?3:0),(int)(height*0.03)+tempy+13);
		}
				
		switch(toolselected)
		{
			case 0:
				switch(action)
				{
					case 0:	//multi select
						if(showRect)
						{
							//System.out.print("multi select"+presssx+","+presssy+","+pressex+","+pressey);
							bufferGraphics.setColor(new Color(0,0,0,100));
							bufferGraphics.fillRect( presssx, presssy, pressex-presssx, pressey-presssy);
							//bufferGraphics.fillRect( presssx, presssy, 100, 100);
						}	
						break;
					case 1://submenu
						//System.out.print("submenux:"+submenux+",submenuy:"+submenux);
						bufferGraphics.setColor(new Color(255,255,255,180));
						bufferGraphics.fillRect( (int)(width*0.16), (int)(height*0.03), 528, 437);
						bufferGraphics.setColor(new Color(0,0,0));
						bufferGraphics.drawRect(submenux+9,submenuy+9,92,124);
						bufferGraphics.setColor(new Color(220,220,220));
						bufferGraphics.fillRect(submenux+10,submenuy+10,90,122);
						bufferGraphics.setColor(new Color(0,0,0));
						bufferGraphics.drawRect(submenux+10,submenuy+10,90,32);
						bufferGraphics.drawString("Activate",submenux+15,submenuy+30);
						bufferGraphics.drawRect(submenux+10,submenuy+42,90,30);
						bufferGraphics.drawString("Deactivate",submenux+15,submenuy+60);
						bufferGraphics.drawRect(submenux+10,submenuy+72,90,30);
						bufferGraphics.drawString("Upload",submenux+15,submenuy+90);
						bufferGraphics.drawRect(submenux+10,submenuy+102,90,30);
						bufferGraphics.drawString("Information",submenux+15,submenuy+120);
						break;
					/*case 2:
						
						break;
					case 0:default:*/
				}
				break;
			case 1:
				if(showLine)
					bufferGraphics.drawLine(presssx, presssy, pressex, pressey);
					
				break;
		}
		g.drawImage(offscreen,0,0,this); 
	}
	public void update(Graphics g)
	{
		//System.out.println("update");
	
		paint(g);
	}
	/*private   class   Handle   implements   ActionListener   
	{   
		public   void   actionPerformed(ActionEvent   e)   
		{           
			repaint();    
		}   
	}*/
	
	private Cursor createCustomCursor(Image cursor, Point hotSpot, String name, ImageObserver ob)
	{   
            
          Dimension bestCursorSize = Toolkit.getDefaultToolkit().getBestCursorSize(cursor.getWidth(ob),cursor.getHeight(ob));   
                    
          BufferedImage bufferedImage = new BufferedImage(   
                  bestCursorSize.width,   
                  bestCursorSize.height,   
                  BufferedImage.TYPE_INT_ARGB   
          );   
          for(int x=0;x<bestCursorSize.width;x++)   
                for(int y=0;y<bestCursorSize.height;y++)     
                      bufferedImage.setRGB(x,y,0);   
          bufferedImage.getGraphics().drawImage(cursor,0,0,ob);   
            
          return Toolkit.getDefaultToolkit().createCustomCursor(bufferedImage, hotSpot, name);   
    
  	}

	
} 
/*  
class graphic
{
	private Vector adjacentnode  = new Vector();
	private Vector nodes  = new Vector();
	public addNode(Node _node)
	{
		nodes.addElement(_node);
	}
}*/
class node
{
	private int posx,posy;
	private int id;
	private int status = 1;
	
	 
	node(int _id, int x, int y)
	{
		id = _id;
		posx = x;
		posy = y;
	}
	public int getid()
	{
		return id;
	}
	public void setid(int _id)
	{
		id = _id;
	}
	public int getx()
	{
		return posx;
	}
	public void setx(int x)
	{
		posx = x;
	}
	public int gety()
	{
		return posy;
	}
	public void sety(int y)
	{
		posx = y;
	}
	public void setStatus(int _status)
	{
		status = _status;
	}
	public int getStatus()
	{
		return status;
	}
	
}  
