package itransnet_base.tracking.Server.Display;
import javax.swing.JTextArea;


public class RealTimeText extends JTextArea implements Runnable {

	private int type=1; //1 left 2 right
	
	public RealTimeText(int type){
		this.type=type;
	}
	
	public void setContent(short[] vids,short[] locs,short[] errs){
		
		String title="";
		String text="";
		if(type==1){
    		title="Vehicle Id  Location\n"; 
    		if(vids!=null){
        	for(int i=0;i<vids.length;i++){
        	 text+=vids[i]+"  ,  "+locs[i]+"\n";
    	    }  
    		}
    	}else{
    		title="Vehicle Id  Erros\n";   
    		if(vids!=null){
    		for(int i=0;i<vids.length;i++){
	        	 text+=vids[i]+"  ,  "+errs[i]+"\n";
        	} 
    		}
    	}    	
    	this.setText(title+text);
	}
	
	
	public void run() {
		/*
		while(true)   
	        {   
	        try   
	        {   
	        	long R = randomNum();	
	        	String title="";
	        	String text="";
	        	
	        	if(type==1){
	        		title="Vehicle Id  Location\n";
	        		short[] vids=Map.defaultMap.getVids();
		        	short[] locs=Map.defaultMap.getLocs();
		        	for(int i=0;i<vids.length;i++){
		        	 text+=vids[i]+"  ,  "+locs[i]+"\n";
	        	    }
		        	Map.defaultMap.setVids(new short[6]);
		        	Map.defaultMap.setLocs(new short[6]);
	        	}else{
	        		title="Vehicle Id  Erros\n";
	        		short[] vid2s=Map.defaultMap.getVids();
	        		short[] errs=Map.defaultMap.getErrs();
	        		for(int i=0;i<vid2s.length;i++){
			        	 text+=vid2s[i]+"  ,  "+errs[i]+"\n";
		        	    }
	        		Map.defaultMap.setVid2s(new short[6]);
		        	Map.defaultMap.setErrs(new short[6]);
	        	}	
	        	
	        	this.setText(title+text);
	        		        	
	            Thread.sleep(2000);   
	        }   
	        catch (InterruptedException e)  {   }   
	        } 
          */
	}
	 private long randomNum()   
	    {      
	        System.out.println((Math.random()*20+80));         
	        return (long)((Math.random()*20+80));   
	    }   
}
 