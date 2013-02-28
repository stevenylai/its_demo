<?php
	//session_start();
	include_once('../../../lib/mysql.class.php');
	
	$debug = true;
	
	if(isset($_REQUEST['NetID']))
	{
		$NetID = $_REQUEST['NetID'];
	
		$db = new mysql();        
		$db->connect();
		
		$sql = "select NID, NPosX, NPosY, NStatus from node where NNetID=".$NetID." order by NID";
		
		//echo $sql."<p>";
		$result = $db->query($sql, $debug);
		
		$count = 0;
		while($row = mysql_fetch_array($result))
		{
			if($count != 0)
				echo "&";
			
			echo "ID".$count."=".$row['NID']."&PosX".$count."=".$row['NPosX']."&PosY".$count."=".$row['NPosY']."&Status".$count."=".$row['NStatus'];
			
			$count++;
		}
		
		echo "&num=".$count;
		
		$db->close();
	}
?>