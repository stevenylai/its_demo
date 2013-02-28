<?php
	include_once('./dblogging.php');
	include_once('./lib/mysql.class.php');
	$db = new mysql();        
	$db->connect();
	$LID =  $_REQUEST['LID'];
	session_start();
	$chk = $_REQUEST['chk_node'];
	$sql = "select DISTINCT NLNID from nodelog where NLLID = $LID";
	//echo $sql;
	$result = $db->query($sql,$debug);
	$num=mysql_num_rows($result);
	$db->close();
	//echo "num : ".$num;
	$_SESSION[LID] = $_REQUEST['LID'];
	if(isset($_REQUEST['chk_node']))
	{
		if(count($_REQUEST['chk_node'])>5)
		{
			$_SESSION[NodeNum]= 5;
		}
		else
		{
			if($num <count($_REQUEST['chk_node']))
				$_SESSION[NodeNum]= num;
			else
				$_SESSION[NodeNum]= count($_REQUEST['chk_node']);
		}
	}
	else
	{
		if($num >5)
			$_SESSION[NodeNum]= 5;
		else
			$_SESSION[NodeNum]= $num ;
	}
	$i=0;
	while($row = mysql_fetch_array($result))
    {
		$_SESSION["mid".$i]=$row['NLNID'];
		//echo "<br />mid:".$_SESSION["mid".$i];
		$i++;
	}
	//echo "NodeNum : ".$_SESSION[NodeNum];
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
<?php
	for($i=0; $i < $_SESSION[NodeNum]; $i++)
    {
		//$_SESSION["mid".$i]=$chk[$i];
?>
swfobject.embedSWF(
"Chart/open-flash-chart.swf", "my_chart<?=$i?>",
"300", "250", "9.0.0", "expressInstall.swf",
{"data-file":"Chart/SI_data.php?i=<?=$i?>"} );
<?php
	}
?>
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
	<table border="0" cellspacing="5px" width="100%">
		<tr height="40px" >
			<td class='tag_over'><u>Sleeping Time</u></td>
			<td class='tag'><a href="./chart/Light_chart.php?LID=<?=$LID?>">Light</a></td>
			<td class='tag' ><a href="./chart/Temp_chart.php?LID=<?=$LID?>">Temperature</a></td>
			<td class='tag'><a href="./per_PL.php?LID=<?=$LID?>">Packet Loss</a></td>
		</tr>
		
	</table>
<?php
	for($i=0; $i < $_SESSION[NodeNum]; $i++)
    {
?>
	<div id="my_chart<?=$i?>" style="float:left"></div>
<?php
  	}
?>
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
			<form action="per_SI.php" method="get"> 
				<div style="width: 180px; height: 150px; overflow: auto">
					<ul>
<?php
			$db = new mysql();        
			$db->connect();
			$sql = "select DISTINCT NLNID from nodelog where NLLID =". $LID." order by NLNID";
			$result = $db->query($sql, $debug);
			$db->close();
			while($row = mysql_fetch_array($result))
			{
				echo"<li><input type='checkbox' name='chk_node[]' id='chk_node'  value='".$row['DMoteID']."' /> <samp class='node' >Node ".$row['NLNID']."</samp></li>";
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
