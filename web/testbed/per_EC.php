<?php
	include_once('./dblogging.php');
	$LID =  $_REQUEST['LID'];
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"><!-- InstanceBegin template="/Templates/defualt.dwt" codeOutsideHTMLIsLocked="false" -->
<head>


<meta http-equiv="Content-Language" content="English" />
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="css/style.css" media="screen" />
<!-- InstanceBeginEditable name="title" -->
<title>WSN-Based Traffic Information System</title>
<script type="text/javascript" src="Chart/js/swfobject.js"></script>
<script type="text/javascript">
swfobject.embedSWF(
  "Chart/open-flash-chart.swf", "my_chart", "640", "480",
  "9.0.0", "expressInstall.swf",
  {"data-file":"Chart/data.php"}
  );
function clickNode(checked)
{
	var obj=document.getElementsByName("chk_node");
	var len = obj.length;
	for (i = 0; i < len; i++)
	{
		obj[i].checked = checked;
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
	<table border="0" cellspacing="5px">
		<tr height="40px" >
			<td class='tag'><a href="per_SI.php?LID=<?=$LID?>">Sleeping Interval</a></td>
			<td class='tag_over' ><a href="per_EC.php?LID=<?=$LID?>">Energy Consumption</a></td>
			<td class='tag'><a href="per_PL.php?LID=<?=$LID?>">Packet Loss</a></td>
		</tr>
		<tr>
			<!--<td colspan="3"><div id="my_chart"></div></td>-->
		</tr>
	</table>
	
  

</div>
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
	  	<h2>Node List</h2>
		</li>
		<li>
			<table border="0" align="center">
				<tr align="center">
					<td style="font-size:12px;" align="center"><a onclick="clickNode(true)"  style="cursor:pointer">Select All</a> | <a onclick="clickNode(false)" style="cursor:pointer">Unselect All</a></td>
				</tr>
			</table>
			<form action="per_EC.php" method="post"> 
				<div style="width: 180px; height: 200px; overflow: auto">
					<ul>
						<!--<li><input type="checkbox" name="chk_node" id="chk_node"  value="0"  onclick="clickNode(1);"/> <samp class='node'>Select All</samp></li>-->
						<li><input type="checkbox" name="chk_node" id="chk_node"  value="0" /> <samp class='node' >Node 1</samp></li>
						<li><input type="checkbox" name="chk_node" id="chk_node"  value="1" /> <samp class='node' >Node 2</samp></li>
						<li><input type="checkbox" name="chk_node" id="chk_node"  value="2" /> <samp class='node' >Node 3</samp></li>
					</ul>
				</div>
				<input type="submit" value='Submit' style=" color:#050;font: bold 84%'trebuchet ms',helvetica,sans-serif; background-color: #fed;"/>
				
			</form>
		</li>
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
