package itransnet_base.tracking.Server.Display;
//Test.java   
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
   
public class StatisticsWindow   
{   
    private RealTimeText RealTimeText=null;
    private RealTimeText RealTimeText2=null;
    private RealTimeChart rtcp=null;	

	public StatisticsWindow(){
		JFrame frame=new JFrame("Statistic Chart");   
	    JScrollPane jScrollPane1 = new javax.swing.JScrollPane();
	    rtcp=new RealTimeChart("Vehicle Statistic","Vehicle Statistic","Number of vehicle");
	    //rtcp.setSize(200, 100);
	    rtcp.setPreferredSize(new Dimension(100, 300));
	    RealTimeText = new RealTimeText(1);
	    RealTimeText2 = new RealTimeText(2);
	    RealTimeText.setColumns(20);
	    RealTimeText.setRows(10);
	    //RealTimeText.setEnabled(false);
	   
	    RealTimeText.setContent(null,null,null);
	   
	    RealTimeText2.setColumns(20);
	    RealTimeText2.setRows(10);
	    //RealTimeText2.setEnabled(false);
	    RealTimeText2.setContent(null,null,null);
	    jScrollPane1.setViewportView(RealTimeText);

	    JPanel panel=new JPanel(); 
	    panel.add(RealTimeText);
	    panel.add(RealTimeText2);
	    
	    frame.getContentPane().add(rtcp,new BorderLayout().SOUTH);   
	    frame.getContentPane().add(panel,new BorderLayout().NORTH); 
	    //frame.setSize(8,6);
	    
	    frame.pack();   
	    frame.setVisible(true);   
	    (new Thread(rtcp)).start();  
	    //(new Thread(RealTimeText)).start(); 
	    //(new Thread(RealTimeText2)).start(); 
	    
	    frame.addWindowListener(new WindowAdapter()    
	    {   
	        public void windowClosing(WindowEvent windowevent)   
	        {   
	            System.exit(0);   
	        }   
	   
	    });   
	}
	
    /**  
     * @param args  
     */   
    public static void main(String[] args)   
    {   
    
    }  
    
    public RealTimeText getRealTimeText() {
		return RealTimeText;
	}

	public void setRealTimeText(RealTimeText realTimeText) {
		RealTimeText = realTimeText;
	}

	public RealTimeText getRealTimeText2() {
		return RealTimeText2;
	}

	public void setRealTimeText2(RealTimeText realTimeText2) {
		RealTimeText2 = realTimeText2;
	}

	public RealTimeChart getRtcp() {
		return rtcp;
	}

	public void setRtcp(RealTimeChart rtcp) {
		this.rtcp = rtcp;
	}
} 

