import java.net.*;
import java.io.*;

public class Client{
 	static Socket server;
 
 	public static void main(String[] args) throws Exception{
  		server=new Socket("158.132.10.187", 5694);
  		BufferedReader in=new BufferedReader(new InputStreamReader(server.getInputStream()));
  		PrintWriter out=new PrintWriter(server.getOutputStream());
  		BufferedReader wt=new BufferedReader(new InputStreamReader(System.in));
	  	while(true){
			String str = in.readLine();	   		
			System.out.println(str);
			if(str.equals("end"))
				break;
	  	}
	  	server.close();
 	}
}