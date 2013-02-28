<?php
	//session_start();
	set_time_limit(0);
	include_once('../lib/mysql.class.php');
	include_once('../config/config.php');

	$debug = true;

	$db = new mysql();        
	$db->connect();
	

		
	$sql = "select value from config where name = 'injectStatus'";
	$result = $db->query($sql,$debug);
	$row = mysql_fetch_array($result);
	$injectStatus = $row['value'];
	
	$sql = "select value from config where name = 'injectMsg'";
	$result = $db->query($sql,$debug);
	$row = mysql_fetch_array($result);
	$injectMsg = $row['value'];
	
	if($injectStatus == 2 || $injectStatus == -1)
	{
		
		$sql = "select value from config where name = 'injectProgram'";
		$result = $db->query($sql,$debug);
		$row = mysql_fetch_array($result);
		$injectProgram = $row['value'];
		
		//$sql = "update program set PStatus=".$injectStatus." where PID = ".$injectProgram;
		$sql = "update program set PStatus=".$injectStatus." where PID = ".$injectProgram;
		$result = $db->query($sql,$debug);
		$sql = "update config set value = '0' where name = 'injectProgram'";
		$result = $db->query($sql,$debug);
		if($injectStatus == 2)
		{
			sleep(10);
			$result = shell_exec($config['EXE_Path']." --login -c 'cd ".$config['CMD_Path']."; java GoodWindowsExec \"export MOTECOM=".$config['port']."; java ".$config['Updater_app']. " \"'");
		//$sql = "update node set NStatus = '3' where NNetID = 1";
			$result = $db->query($sql,$debug);
		}
	}
$db->close();
	echo ($injectStatus."/".$injectMsg);
	
?>
