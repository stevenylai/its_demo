<?php
	
	include_once('./dblogging.php');
	include_once('./lib/mysql.class.php');
	
	$debug = false;
	
	$db = new mysql();        
	$db->connect();

	$sql = "select * from user where UID = '".$_SESSION['user']['id']."'";
	//echo $sql;
	$result = $db->query($sql,$debug);
	$row = mysql_fetch_array($result);
	
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
	
	<h1>User Information</h1>
   <br />
    <table cellpadding="5" cellspacing="2" border="0" width="100%" bgcolor="#FFFFFF">
    	<tr >
        	<td>First Name: </td>
            <td><?=$row['UFName']?></td>
        </tr>
        <tr bgcolor="#CCCCCC">
        	<td>Last Name: </td>
            <td><?=$row['ULName']?></td>
        </tr>
        <tr>
        	<td>Email:</td>
            <td><?=$row['UEmail']?></td>
        </tr>
        <tr bgcolor="CCCCCC">
        	<td>Role:</td>
            <td><?php switch ($row['UType'])
					{
						case 0:echo"General User";break;
						case 1:echo"Administrator";break;
						default: echo"General User";
					}?></td>
        </tr>
		<tr><td colspan="2"><a href="#">Edit</td></tr>
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
