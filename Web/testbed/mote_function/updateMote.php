<?php
	set_time_limit(0);
	include_once('../config/config.php');
	
	$result = shell_exec($config['EXE_Path']." --login -c 'cd ".$config['CMD_Path']."; java GoodWindowsExec \"export MOTECOM=".$config['port']."; java ".$config['Updater_app']. " \"'");
	//echo $config['EXE_Path']." --login -c 'cd ".$config['CMD_Path']."; java GoodWindowsExec \"export MOTECOM=".$config['port']."; java ".$config['Updater_app']. " \"'";	
	echo ("status=1");
	
?>
