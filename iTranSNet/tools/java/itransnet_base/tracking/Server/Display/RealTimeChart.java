package itransnet_base.tracking.Server.Display;
//RealTimeChart .java   
import org.jfree.chart.ChartFactory;   
import org.jfree.chart.ChartPanel;   
import org.jfree.chart.JFreeChart;   
import org.jfree.chart.axis.ValueAxis;   
import org.jfree.chart.plot.XYPlot;   
import org.jfree.chart.renderer.xy.DefaultXYItemRenderer;
import org.jfree.data.time.Millisecond;   
import org.jfree.data.time.TimeSeries;   
import org.jfree.data.time.TimeSeriesCollection;   
   
public class RealTimeChart extends ChartPanel implements Runnable   
{   
	private int vechileNum1=0;
	private int vechileNum2=0;
    public static int road1=1;
    public static int road2=2;
	
	private static TimeSeries timeSeries; 
    private static TimeSeries timeSeries2; 
    private long value=0;   
       
    public RealTimeChart(String chartContent,String title,String yaxisName)   
    {   
        super(createChart(chartContent,title,yaxisName));   
    }   
       
    private static JFreeChart createChart(String chartContent,String title,String yaxisName){   
        //创建时序图对象   
        timeSeries = new TimeSeries("Road 1",Millisecond.class);  
        timeSeries2 = new TimeSeries("Road 2",Millisecond.class);  
        TimeSeriesCollection timeseriescollection = new TimeSeriesCollection(timeSeries);   
        TimeSeriesCollection timeseriescollection2 = new TimeSeriesCollection(timeSeries2);   
        JFreeChart jfreechart = ChartFactory.createTimeSeriesChart(title,"Time(Second)",yaxisName,timeseriescollection,true,true,false);   
        XYPlot xyplot = jfreechart.getXYPlot();   
        //纵坐标设定   
        ValueAxis valueaxis = xyplot.getDomainAxis();   
        //自动设置数据轴数据范围   
        valueaxis.setAutoRange(true);   
        //数据轴固定数据范围 30s   
        valueaxis.setFixedAutoRange(30000D);  
          
   
        valueaxis = xyplot.getRangeAxis();   
        //valueaxis.setRange(0.0D,200D);   
        xyplot.setDataset(1, timeseriescollection2);
        xyplot.setRenderer(1,new DefaultXYItemRenderer());
        return jfreechart;   
      }   
   
    public void run()   
    {   
        while(true)   
        {   
        try   
        {   
        	//long R = randomNum();
            timeSeries.add(new Millisecond(), vechileNum1);   
            timeSeries2.add(new Millisecond(), vechileNum2);   
            Thread.sleep(2000);   
        }   
        catch (InterruptedException e)  {   }   
        }          
    }   
   
    public void caclulateVehicleNumber(short[] locs)   
    {    
    	int vNum1=0;
    	int vNum2=0;
    	for(int i=0;i<locs.length;i++){
       	 if(locs[i]==road1){
       		vNum1++; 
       	 }
       	if(locs[i]==road2){
       		vNum2++; 
       	 }
   	    }
        if(vNum1>0){
        	vechileNum1=vNum1;
        } 
        if(vNum2>0){
        	vechileNum2=vNum2;
        }	         
    }
   
    
    private long randomNum()   
    {      
        System.out.println((Math.random()*20+80));         
        return (long)((Math.random()*20+80));   
    }

	public int getVechileNum1() {
		return vechileNum1;
	}

	public void setVechileNum1(int vechileNum1) {
		this.vechileNum1 = vechileNum1;
	}

	public int getVechileNum2() {
		return vechileNum2;
	}

	public void setVechileNum2(int vechileNum2) {
		this.vechileNum2 = vechileNum2;
	}

	
}   
