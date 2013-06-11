<?php
	include_once('./dblogging.php');
	include_once('./lib/mysql.class.php');
	
	$db = new mysql();        
	$db->connect();
	
	$sql = "select PID from program where PStatus = 4";
	$result = $db->query($sql,false);
	$row = mysql_fetch_array($result);
	$PID = $row['PID'];
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"><!-- InstanceBegin template="/Templates/defualt.dwt" codeOutsideHTMLIsLocked="false" -->
<head>


<meta http-equiv="Content-Language" content="English" />
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="css/style.css" media="screen" />
<!-- InstanceBeginEditable name="title" --><title>WSN Management System</title>
<meta http-equiv="pragme" content="no-cache">
	<link rel="stylesheet" href="css/thickbox.css" type="text/css" media="screen" />
	
	<script src="js/jquery.js" type="text/javascript"></script>
	<script src="js/thickbox.js" type="text/javascript"></script>
	<script>
function postRequest(type)
			{
				  var xmlHttp;
				  if(window.XMLHttpRequest)
				  { // For Mozilla, Safari, ...
				  	//alert("Mozilla");
						var xmlHttp = new XMLHttpRequest();
				  }
				  else if(window.ActiveXObject)
				  { // For Internet Explorer
				  //alert("IE");
						var xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
				  }
				  switch(type)
				  {
				  	case 1:
						xmlHttp.open('POST', "mote_function/startListener.php?PID=<?=$PID?>&interval="+document.getElementById("interval").value, true);
						break;
					case 2:
						
						xmlHttp.open('POST', "mote_function/killListener.php",true);
						break;
				  }
				  
				  xmlHttp.onreadystatechange = function()
				  {
				  		
						if (xmlHttp.readyState == 4)
						{
							//alert("xmlHttp.readyState:"+xmlHttp.readyState);
							//str = xmlHttp.responseText;
							//document.getElementById("div_content").innerHTML ="Success<br /><img src='images/loader.PNG' /><br />	<input type='button' onclick='window.location.reload()' value='OK' /></p>";
							document.getElementById("div_content").innerHTML ="Success<br /><img src='images/loader.PNG' /><br /><input type='button' onclick='window.location.reload()' value='OK' />";
						}
				  }
				  
				  switch(type)
				  {
				  	case 1:
						xmlHttp.send("startListener.php");
						break;
					case 2:
						xmlHttp.send("killListener.php");
						break;
				  }
				  //xmlHttp.send("installprogram.php?PID="+PID+"&Slot="+Slot);
			}

</script>
<!-- InstanceEndEditable -->
</head>
<body>

<div id="wrap">

<div id="top"></div>

<div id="content">

<div class="header">
<h1><a href="#">WSN-Based Traffic Information System </a></h1>
<h2>&nbsp;</h2>
<span style="float:right; padding-right:5px; color:#FFF">
<?php if($_SESSION['user']['type']==1) echo "<a href='./User_UM.php'>Admin Tool</a> | "  ?><a href="User_UI.php">User</a> | <a href="dblogout.php">Logout</a></span>
</div>

<!--<div class="breadcrumbs">
<a href="#">Home</a> &middot; You are here
</div>-->

<!-- InstanceBeginEditable name="context" -->
<div class="middle">
<?php	
	
	
	$sql = "select * from config where name = 'LisPID'";
	$result = $db->query($sql,false);
	$row = mysql_fetch_array($result);
	$sql = "select count(*) as c from program where PStatus = 4";
	$result = $db->query($sql,false);
	$row2 = mysql_fetch_array($result);
	//echo "bhjbhj:".$row['value'];
?>	
	<table> 
		<tr><td align="center">Sencing Application: <?php if($row['value']==0) echo "<input type='submit' value='Start' ".($row2['c']==0?"disabled='disabled'":"")."class='thickbox' onclick='postRequest(1)' alt='#TB_inline?height=90&amp;width=240&amp;inlineId=div_loading&modal=true'/>"; else echo "<input type='submit' value='Stop'  class='thickbox' onclick='postRequest(2)' alt='#TB_inline?height=90&amp;width=240&amp;inlineId=div_loading&modal=true'/>";?></td>
		<td>sampling rate: 
		  <input id="interval" name="interval" type="text" value="1000" size="10"   <?php if($row['value']!=0) echo "disabled='disabled'";?>/>
		ms</td></tr>
		<tr><td colspan="2">
  <object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=7,0,19,0" width="518" height="427">
    <param name="movie" value="Flash/map/map_view.swf" />
    <param name="quality" value="high" />
	<param name="wmode" value="transparent">
	
    <embed src="Flash/map/map_view.swf" quality="high" pluginspage="http://www.macromedia.com/go/getflashplayer" type="application/x-shockwave-flash" width="518" height="427" wmode="transparent"></embed>
  </object>
  </td></tr></table>

</div>
<DIV id="div_loading" style="display:none">
<p id='div_content'>
	
	Please wait...
	<br />
	<img src="images/ajax-loader.gif" alt="" />
	</P>
			 
</DIV>
<!-- InstanceEndEditable -->
<div class="right">
		
<!-- end #content -->

<div id="sidebar"><!-- #BeginLibraryItem "/Library/Untitled.lbi" -->	<table cellpadding="0" cellspacing="0" width="180px">
    	<tr>
        	<td><h2>Functions</h2></td>
        </tr> 
        
		<tr><td><li><a href="User_pro.php">Program</a></li></td></tr>
        <tr><td><li><a href="configure.php">Configure</a></li></td></tr>
        <tr><td><li><a href="network.php">Network</a></li></td></tr>
        <tr><td><li><a href="performance_list.php">Performance</a></li></td></tr>
        <tr><td><li><a href="history_list.php">History</a></li></td></tr>
		<tr><td><li><a href="Log.php">Log</a></li></td></tr> 
    </table><!-- #EndLibraryItem --><ul>
  <li>
    <!-- InstanceBeginEditable name="sub_sidebar" -->
	  
	  <!-- InstanceEndEditable -->
    </li>
</ul>
  
</div>

<!-- end #sidebar -->
</div>

<div id="clear"></div>

</div>

<div id="bottom"></div>

</div>

<div id="footer">
Provide by <a href="Templates/www.comp.polyu.edu.hk">Polyu</a>
</div>

</body>
<!-- InstanceEnd --></html>
