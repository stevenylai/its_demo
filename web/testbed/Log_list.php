<?php
	include_once('./dblogging.php');
	include_once('./lib/mysql.class.php');
	include_once('./lib/page.class.php');
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"><!-- InstanceBegin template="/Templates/defualt.dwt" codeOutsideHTMLIsLocked="false" -->
<head>


<meta http-equiv="Content-Language" content="English" />
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="css/style.css" media="screen" />
<!-- InstanceBeginEditable name="title" --><title>WSN-Based Traffic Information System</title>
<script type="text/JavaScript">
<!--
function MM_goToURL() { //v3.0
  var i, args=MM_goToURL.arguments; document.MM_returnValue = false;
  for (i=0; i<(args.length-1); i+=2) eval(args[i]+".location='"+args[i+1]+"'");
}

function clickNode(checked)
{
	var obj=document.getElementsByName("chk_node[]");
	var len = obj.length;
	for (i = 0; i < len; i++)
	{
		obj[i].checked = checked;
	} 
}
//-->
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
<!--<p><h1>Log</h1></p>-->
<table border="0" cellspacing="5px" width="100%">
<tr  height="40px" >
<td class='tag_over'><u>Sensor</u></td><td class='tag'><a href="UserData_list.php?LID=<?=$_REQUEST['LID']?>" >User Data</a></td>
</tr>
</table>
<br />
<table border="0" width=100% align="center">

<?php
	
	$db = new mysql();        
	$db->connect();
	
	$chk = $_REQUEST['chk_node'];
	$ex ="";
	$str_chk = "";
	for($i=0; $i < count($_REQUEST['chk_node']); $i++)
    {
		$str_chk .= " chk_node[] = ".$chk[$i];
		if($i == 0)
		{
			$ex .=" and NLNID=".$chk[$i];
		}
		else
		{
			$ex .= " or NLNID=".$chk[$i];
    	}
	}
	$sql = "SELECT * FROM nodelog where NLLID =".$_REQUEST['LID'].$ex." order by NLID DESC ";
	$result = $db->query($sql, $debug);
	$page = new page(mysql_num_rows($result),50);
	
	//$sql = "SELECT Dtime, DMoteID, Dtemp, DPhoto, DLID FROM `data`, listener where DLID = LID and LID =".$_REQUEST['LID'].$ex." order by Dtime DESC ";
	
	$sql .= " LIMIT " . $page->getStart() . ", " . $page->getPer();
	//echo $sql;
	
	$result = $db->query($sql, true);
	$db->close();
?>
<tr>
	<td align="left" colspan="4"> <?php $page->showPagebar('./Log_list.php?LID='.$_REQUEST['LID']); ?></td><td align="right"><input type="button" onclick="MM_goToURL('parent','export-xls(log).php?<?=$str_chk?>&LID=<?=$_REQUEST['LID']?>');return document.MM_returnValue" value="Export" /></td>
</tr>
<tr bgcolor="#33CCFF">
	
	<td align="center"><strong>No.</strong></td>
	<td align="center"><strong>Node ID</strong></td>
	<td align="center"><strong>Type</strong></td>
	<td align="center"><strong>Status</strong></td>
	<td align="center"><strong>Date</strong></td>
</tr>
<?php
	$count = 1;
	while($row = mysql_fetch_array($result))
	{
		if($count % 2 == 0)
			echo "<tr bgcolor='#CCCCCC'>";
		else
			echo "<tr>";
			
		echo "<td align='center'>".($count+$page->getStart())."</td>";
		echo "<td align='center'>".$row['NLNID']."</td>";
		switch ($row['NLTYPE'])
		{
			case 1:
				echo "<td align='center'>Sensor Status</td>";
				break;
			default:
				echo "<td align='center'>".$row['NLTYPE']."</td>";
				
		}
		switch ($row['NLTYPE'])
		{
			case 1:
				if($row['NLStatus'] == 1)
					echo "<td align='center'>Activative</td>";
				else
					echo "<td align='center'>Deactivative</td>";
				break;
			default:
				echo "<td align='center'>".$row['NLStatus']."</td>";
				
		}
		//echo "<td align='center'>".$row['NLStatus']."</td>";
		echo "<td align='center'>".$row['NLDate']."</td>";
		echo "</tr>";
		$count++;
	}
?>
<tr>
	<td align="left" colspan="7"> <?php $page->showPagebar('./Log_list.php?LID='.$_REQUEST['LID']); ?></td>
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
			<form action="Log_list.php" method="get"> 
				<div style="width: 180px; height: 150px; overflow: auto">
					<ul>
<?php
			$db->connect();
			//$sql = "SELECT DISTINCT DMoteID FROM `data` , listener  where DLID = LID and LPID =".$_REQUEST['PID']." order by DMoteID";
			$sql = "SELECT DISTINCT NLNID FROM nodelog where NLLID =".$_REQUEST['LID']." order by NLID DESC ";
			$result = $db->query($sql, $debug);
			$db->close();
			while($row = mysql_fetch_array($result))
			{
				echo"<li><input type='checkbox' name='chk_node[]' id='chk_node'  value='".$row['NLNID']."' /> <samp class='node' >Node ".$row['NLNID']."</samp></li>";
			}
?>
					</ul>
				</div>
				<input type="submit" value='Submit'/>
				<input type="hidden" value="<?=$_REQUEST['LID']?>" name="LID"/>
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
