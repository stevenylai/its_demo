<?php
	//session_start();
	include_once('../../../lib/mysql.class.php');
	echo "?zz=1";
	$debug = true;
	
	$db = new mysql();        
	$db->connect();
	
	//$sql = "select PID, PName from program where PStatus = 2 and PUID =".$_SESSION['user']['id'];
	$sql = "select PID, PName,PStatus from program where PStatus = 2 or PStatus = 4 order by PSlot";

	//$sql = "select PID, PName from program where PUID =1";
	//echo $sql;
	$result = $db->query($sql, $debug);
	
	$count = 0;
	$selected = -1;
	while($row = mysql_fetch_array($result))
	{
		//if($count == 0)
		//	echo "p".$count."=".$row['PName']."&id".$count++."=".$row['PID'];
		//else
			echo "&p".$count."=".$row['PName']."&id".$count++."=".$row['PID'];
		if($row['PStatus']==4)
			$selected = $count;
	}
	
	echo "&num=".$count;
	if($selected == -1)
		echo "&select=0";
	else
		echo "&select=".$selected;
	$db->close();
?>