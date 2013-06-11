<?php
	include_once('./dblogging.php');
	include_once('./lib/mysql.class.php');
	include_once('./lib/page.class.php');
	
	$db = new mysql();        
		$db->connect();
		
		$result = $db->query("SELECT * FROM listener,program where  LPID = PID ", $debug);
		$page = new page(mysql_num_rows($result),50);
		
		$sql = "SELECT * FROM listener,program where  LPID = PID order by LID DESC ";
		
		$sql .= " LIMIT " . $page->getStart() . ", " . $page->getPer();
		
		$result = $db->query($sql, true);
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"><!-- InstanceBegin template="/Templates/defualt.dwt" codeOutsideHTMLIsLocked="false" -->
<head>


<meta http-equiv="Content-Language" content="English" />
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="css/style.css" media="screen" />
<!-- InstanceBeginEditable name="title" --><title>WSN Management System</title><!-- InstanceEndEditable -->
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
  <p><h1>History</h1></p>
  <br/>
	<table width="100%">
<tr>
	<td align="left" colspan="7"> <?php $page->showPagebar('./history_list.php?'); ?></td></td>
</tr>
		<tr bgcolor="#33CCFF">
			<td align="center"><strong>No.</strong></td>
			<td align="center"><strong>Program Name</strong></td>
			<td align="center"><strong>Created Date</strong></td>
			<!--<td align="center"><strong>End Time</strong></td>-->
		</tr>
<?php
		$count = 1;
		while($row = mysql_fetch_array($result))
		{
			if($count % 2 == 0)
				echo "<tr bgcolor='#CCCCCC'>";
			else
				echo "<tr >";
			
			$sql2 = "SELECT * FROM `data`, listener where DLID = ".$row['LID'];
			$result2 = $db->query($sql2, $debug);
				
			echo "<td align='center'>".($count+$page->getStart())."</td>";
			if(mysql_num_rows($result2)>0)
				echo "<td align='center'><a href='history.php?LID=".$row['LID']."'>".$row['PName']."</a></td>";
			else
				echo "<td align='center'>".$row['PName']."</td>";
				
			echo "<td align='center'>".$row['PStart']."</td>";
			//echo "<td align='center'>".$row['PEnd']."</td>";
				
			echo "</tr>";
			$count++ ;
		}
		
		$db->close();
		
		
	
?>		
	<tr>
	<td align="left" colspan="7"> <?php $page->showPagebar('./history_list.php?'); ?></td>
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
