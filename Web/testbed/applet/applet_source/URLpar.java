
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
 
public class URLpar {
 
   private Map<String, String> paramValue = new HashMap<String, String>();
 
 
   public URLpar(String url) {
 
	   //String url = getDocumentBase().toString();
	   if (url.indexOf("?") > -1) {
		   String paramaters = url.substring(url.indexOf("?") + 1);
		   parseParam(paramaters);
	   }
   }
 
   //parse the URL parameter
   private void parseParam(String parameters){
 
	   StringTokenizer paramGroup = new StringTokenizer(parameters, "&");
 
	   while(paramGroup.hasMoreTokens())
	   	{
 
		   StringTokenizer value = new StringTokenizer(paramGroup.nextToken(), "=");
		   paramValue.put(value.nextToken(), value.nextToken());
 
	   }
   }
 
   public String getToken(String key) 
   {
		try
		{
			return paramValue.get(key); 
		}catch(Exception e)
		{
			return null;
		}
   }
}