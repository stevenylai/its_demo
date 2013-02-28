<?php
	
	include_once('./dblogging.php');
	include_once('./lib/mysql.class.php');
	
	$debug = false;
	
	$db = new mysql();        
	$db->connect();

	$sql = "select * from user ";
	//echo $sql;
	$result = $db->query($sql,$debug);
	//$row = mysql_fetch_array($result);
	
	$db->close();
	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"><!-- InstanceBegin template="/Templates/defualt.dwt" codeOutsideHTMLIsLocked="false" -->
<head>


<meta http-equiv="Content-Language" content="English" />
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="css/style.css" media="screen" />
<!-- InstanceBeginEditable name="title" --><title>WSN-Based Traffic Information System</title><!-- InstanceEndEditable -->
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
	
   <table width="100%" height="40px">
   	<tr>
   	<td class="tag"><a href="User_UM.php">User Management</a></td><td class="tag_over"><u>Map Edit</u></td></tr>
   </table>
   <br />
   <object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=7,0,19,0" width="581" height="460">
  <param name="movie" value="Flash/map/map_edit.swf" />
  <param name="quality" value="high" />
  <embed src="Flash/map/map_edit.swf" quality="high" pluginspage="http://www.macromedia.com/go/getflashplayer" type="application/x-shockwave-flash" width="581" height="460"></embed>
</object>

	<br />
	<br />
	<!--<form action="addUser.php" method="post" >
		<table width="100%">
			<tr bgcolor="#33CCFF"><td colspan="4">Add user</td></tr>
			<tr>
				<td>User Name:</td><td><input type="text" name="name" /></td><td>Password:</td><td><input type="password" name="pwd"/></td>
			</tr>
			<tr><td colspan="2"><input type="submit" value="Submit"/></td><td colspan="2"><input type="reset" value="Reset"/></td></tr>
			
		</table>
	</form>-->
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
