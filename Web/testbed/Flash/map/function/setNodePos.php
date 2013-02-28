<?php
set_time_limit(0);
	echo "?num=1";
	include_once('../../../lib/mysql.class.php');
	
	$debug = true;
	$db = new mysql();        
	$db->connect();
		
	
	
	if(isset($_REQUEST['num']) && isset($_REQUEST['NetID']))
	{
		$NetID = $_REQUEST['NetID'];
		
		for ($i = 0 ; $i <$_REQUEST['num'] ; $i++ )
		{
			$sql = "Update node set NPosX= ".$_REQUEST['x'.$i]." , NPosY= ".$_REQUEST['y'.$i]." where NID=".$_REQUEST['id'.$i];
			$result = $db->query($sql, $debug);
		}
		
		echo "1";
	}
	echo "0";
	$db->close();
?>