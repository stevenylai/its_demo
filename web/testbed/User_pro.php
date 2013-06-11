<?php
	
	include_once('./dblogging.php');
	include_once('./lib/mysql.class.php');
	
	$debug = false;
	
	$db = new mysql();        
	
	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"><!-- InstanceBegin template="/Templates/defualt.dwt" codeOutsideHTMLIsLocked="false" -->
<head>


<meta http-equiv="Content-Language" content="English" />
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="css/style.css" media="screen" />
<!-- InstanceBeginEditable name="title" --><title>WSN-Based Traffic Information System</title>
	<link rel="stylesheet" href="css/thickbox.css" type="text/css" media="screen" />
	
	<script src="js/jquery.js" type="text/javascript"></script>
	<script src="js/thickbox.js" type="text/javascript"></script>
	

<script>
function postRequest(PID,Slot,type)
			{
			//alert("TYPe");
				  var xmlHttp;
				  if(window.XMLHttpRequest)
				  { // For Mozilla, Safari, ...
						var xmlHttp = new XMLHttpRequest();
				  }
				  else if(window.ActiveXObject)
				  { // For Internet Explorer
						var xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
				  }
				  switch(type)
				  {
				  	case 1:
						xmlHttp.open('POST', "mote_function/installprogram.php?PID="+PID+"&Slot="+Slot, true);
						break;
					case 2:
						
						xmlHttp.open('POST', "mote_function/delprogram.php?txt_PID="+PID,true);
						break;
				  }
				  
				  //xmlHttp.open('POST', "installprogram.php?PID="+PID+"&Slot="+Slot, true);
				  //xmlHttp.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
				  xmlHttp.onreadystatechange = function()
				  {
						if (xmlHttp.readyState == 4)
						{
							
							str = xmlHttp.responseText;
							//alert(str);
							//document.getElementById("div_content").innerHTML = "Success<br /><img src='images/loader.PNG' /></span>	<br />	<input type='button' onclick='window.location.reload()' value='OK' /></P>";
							switch(type)
							  {
								case 1:
									postRequest2(type);
									break;
								case 2:
									document.getElementById("div_content").innerHTML = "Success<br /><img src='images/loader.PNG' /><br /><input type='button' onclick='window.location.reload()' value='OK' />";
									break;
								}
							
						}
				  }
				  
				  switch(type)
				  {
				  	case 1:
						xmlHttp.send("installprogram.php?PID="+PID+"&Slot="+Slot);
						break;
					case 2:
						xmlHttp.send("dbdelprogram.php?txt_PID="+PID);
						break;
				  }
				  //xmlHttp.send("installprogram.php?PID="+PID+"&Slot="+Slot);
			}


function postRequest2(type)
			{
				  var xmlHttp;
				  if(window.XMLHttpRequest)
				  { // For Mozilla, Safari, ...
						var xmlHttp = new XMLHttpRequest();
				  }
				  else if(window.ActiveXObject)
				  { // For Internet Explorer
						var xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
				  }
				  
				  switch(type)
				  {
				  	case 1:
						xmlHttp.open('POST', "mote_function/injectStatus.php", true);
						break;
				  }
				  
				  //xmlHttp.open('POST', "installprogram.php?PID="+PID+"&Slot="+Slot, true);
				  //xmlHttp.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
				  xmlHttp.onreadystatechange = function()
				  {
						if (xmlHttp.readyState == 4)
						{
							
							switch(type)
						  {
				  			case 1:
								str = xmlHttp.responseText;
								//alert(str);
								if(str !="")
								{
									arr = str.split("/");
		
									if(arr[0] == 1 || arr[0] == 0)
									{
										if(arr[1] !="")
											document.getElementById("div_content").innerHTML = "Please wait...<br>( "+arr[1]+" )<br /><img src='images/ajax-loader.gif'  /></span>";
										var t=setTimeout("postRequest2("+type+")",5000);
									}
									else
									{
										if(arr[0]==2)
											document.getElementById("div_content").innerHTML = "Success";
										else
											document.getElementById("div_content").innerHTML = "<H2>Error</H2>";
										document.getElementById("div_content").innerHTML += "<br /><img src='images/loader.PNG' /></span>	<br />	<input type='button' onclick='window.location.reload()' value='OK' />";
									}
								}
								break;
							
							}
						}
				  }
				  
				  switch(type)
				  {
				  	case 1:
						xmlHttp.send("injectStatus.php");
						break;
				  }
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
    <H1>Program</H1>
    <table cellspacing="30" border="0" width="94%" >
    	<tr ><td>
			<table width="94%" border="0" cellspacing="0" cellpadding="0">
				
			<?php
				for($i = 1 ; $i <= 2 ; $i++ )
				{
			?>
					<tr>
						<td colspan="2"><H2>Slot <?=$i?>.</H2></td>
					</tr>
			<?php
					$db->connect();
	
					$sql = "select * from program where PStatus != 3 and PSlot = ".$i;
					//echo $sql;
					$result = $db->query($sql,$debug);
					$db->close();
					if(mysql_num_rows($result) > 0)
					{
						$row = mysql_fetch_array($result)
			?>
			  	<tr style="background-color:#CCCCCC">
					<td> Name:</td>
					<td><?=$row['PName']?></td>
			  	</tr>
			  	<tr>
					<td> Status:</td>
					<td><?php 
						switch ($row['PStatus'])
						{
							case -1 : echo "File does not include Deluge";break;
							case 0: echo "File Error";break;
							case 1: echo "Uploaded";break;
							case 2: echo "Installed";break;
							case 4: echo "Running";break;
							default: echo "Error";
						}
					?></td>
				</tr>
				<tr style="background-color:#CCCCCC">
					<td> Created Date:</td>
					<td><?=$row['PDate']?></td>
				</tr>
				 <tr>
					<td align="right">
					<?php
						if($row['PStatus'] != 0 )
						{
					?>
						<!--<form action="mote_function/installprogram.php?PID=<?=$row['PID']?>&Slot=<?=$i?>" method="post">--><input type="submit" class="thickbox" value="Install" <?php if($row['PStatus'] != 1 ) echo"disabled=disabled"?> onclick="postRequest(<?=$row['PID']?>,<?=$i?>,1)" alt="#TB_inline?height=120&amp;width=240&amp;inlineId=div_loading&modal=true" /><!--</form>-->
					<?php
						}
					?>
					</td>
					<td align="left"><!--<form action="dbdelprogram.php?txt_PID=<?=$row['PID']?>" method="post">--><input type="submit" value="Delete" class="thickbox" onclick="postRequest(<?=$row['PID']?>,<?=$i?>,2)" alt="#TB_inline?height=120&amp;width=240&amp;inlineId=div_loading&modal=true"/><!--</form>--></td>
				</tr>
			<?php
				}
				else
				{
					echo "<tr><td align='center' colspan='2'><H1>Empty</H1></td></tr><tr><td align='right' colspan='2'><a href='addprogram.php?s=".$i."'> Add program</a></td></tr>";
				}
			?>
			
				<tr><td height="10px"></td></tr>
			<?php
				}
			?>
				
				
			
			</table>

			
         </td></tr>
    </table>
</div>
<DIV id="div_loading" style="display:none">
<p id='div_content'>
	
	Please wait...
	<br />
	<img src="images/ajax-loader.gif" alt="" /></span>
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
