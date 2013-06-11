<?php
//header("Location:http://www.google.com");
header("content-type: text/xml");
echo "<chart caption='Site hits per hour' subCaption='In Thousands' numdivlines='9' lineThickness='2' showValues='0' anchorRadius='3' anchorBgAlpha='50' showAlternateVGridColor='1' numVisiblePlot='12' animation='0'>";
include_once('./lib/mysql.class.php');
	$db = new mysql();        
	$db->connect();
	//$sql = "SELECT Dtime, Dtemp, DPhoto FROM `data` ";
	$sql = "SELECT Dtime FROM `data` group by Dtime";
	$result = $db->query($sql, $debug);
	echo "<categories>";
	while($row = mysql_fetch_array($result))
	{
		
		echo "<category label='".$row['Dtime']."' />";
		
	}
	echo "</categories>";
	$sql = "SELECT Dtemp FROM `data` where DMoteID =11";
	$result = $db->query($sql, $debug);
	echo "<dataset seriesName='Temp' color='008080' anchorBorderColor='008080'>";
	while($row = mysql_fetch_array($result))
	{
		echo "<set value='".$row['Dtemp']."' />";
	}
	echo "</dataset>";
	
	$sql = "SELECT DPhoto FROM `data` where DMoteID =11";
	$result = $db->query($sql, $debug);
	echo "<dataset seriesName='Light' color='800080' anchorBorderColor='800080'>";
	while($row = mysql_fetch_array($result))
	{
		echo "<set value='".$row['DPhoto']."' />";
	}
	echo "</dataset>";
	$db->close();
	echo "</chart>";
?>