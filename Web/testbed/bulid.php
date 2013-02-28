<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=big5" />
<title>Untitled Document</title>
<script type="text/javascript">

var xmlhttp=null;

function ajax(str)
{
	//if (str.length==0)
	//{ 
		//document.getElementById("msgbox").innerHTML="";
		//return;
	//}
	if (window.XMLHttpRequest)
	{
		// code for IE7+, Firefox, Chrome, Opera, Safari
		xmlhttp=new XMLHttpRequest();
	}
	else
	{
		// code for IE6, IE5
		xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
	}
	
	if(str==1)
	{  
		document.getElementById('msg_Bulid').innerHTML='Loading..';
		document.getElementById('Bulid').disabled = true;
		  
	}
	else
	{
		document.getElementById('msg_Install').innerHTML='Loading..';
		document.getElementById('Install').disabled = true;
		
	}  
	
	var url="test.php?id="+str;
	//url=url+"&sid="+Math.random();
	//alert("Please Wait");
	
	xmlhttp.onreadystatechange = function()
	{
		if (xmlhttp.readyState == 4)
		{
			
			//str = xmlHttp.responseText;
			document.getElementById("msgbox").value+=xmlhttp.responseText+"\n";
			document.getElementById('Bulid').disabled = false;
			document.getElementById('Install').disabled = false;
			document.getElementById('msg_Bulid').innerHTML="";
			document.getElementById('msg_Install').innerHTML="";
		}
	}
	xmlhttp.open("GET",url,true);
	xmlhttp.send(null);
//alert(xmlhttp.responseText);

}
</script> 
</head>

<body>
<h1>Blink</h1>
<table>
	<tr>
		<td>Bulid</td>
		<td><input type="button"  value="Start" id="Bulid" onclick="ajax(1);"/><span id='msg_Bulid'></span></td>
	</tr>
	<tr>
		<td>Install</td>
		<td><input type="button"  value="Start" id="Install" onclick="ajax(2);"/><span id='msg_Install'></span></td>
	</tr>
</table>
<textarea name="textarea" cols="100" rows="50" id="msgbox"></textarea>
</body>
</html>
