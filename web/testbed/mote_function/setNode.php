<?php
set_time_limit(0);
	echo "?num=1";
	require_once('../config/config.php');
	include_once('../lib/mysql.class.php');
	
	$debug = true;
	$db = new mysql();        
	$db->connect();
		
	$sql = "Update config set value= NOW( ) where name='lastMoteUpdate'";
	$result = $db->query($sql, $debug);
	
	if(isset($_REQUEST['num']) && isset($_REQUEST['NetID']))
	//if(isset($_REQUEST['num']))
	{
		$NetID = $_REQUEST['NetID'];
		
		for ($i = 0 ; $i <$_REQUEST['num'] ; $i++ )
		{
				if($_REQUEST['status'.$i]==1)
					$status = 3;
				else
					$status = 4;
				$result = shell_exec($config['EXE_Path']." --login -c 'cd ".$config['CMD_Path']."; java GoodWindowsExec \"export MOTECOM=".$config['port']."; java ".$config['MM_app']." ".$status." ".$_REQUEST['id'.$i]." \"'");
				//echo "<p>".$config['EXE_Path']." --login -c \"export MOTECOM=".$config['port'].";java ".$config['MM_app']." ".$status." ".$_REQUEST['id'.$i]."\"</p>";
				//echo "<p>$result</p>";
		}
		
		echo "1";
	}
	echo "0";
	$db->close();
?>