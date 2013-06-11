<?php
	session_start();
	set_time_limit(0);
	include_once('../config/config.php');
	include_once('../lib/mysql.class.php');
	include_once('../lib/process.class.php');
?>
<pre>
<?php
	$debug = true;
	$PID = $_REQUEST['PID'];
	//$Slot = $_REQUEST['Slot'];
	//echo $PID ;
	
	$db = new mysql();        
	$db->connect();
		
	$sql = "select * from config where name = 'LisPID'";
	$result = $db->query($sql, $debug);
	$row = mysql_fetch_array($result);
	
	$exe = new exeC();
	
	if($row['value'] != 0 && $exe->kill($row['value']))
	{
		$sql = "update config set value = 0 where name = 'LisPID'";
		$result = $db->query($sql, $debug);
		//$sql = "Update config set value= 1 where name='seqno'";
		//$result = $db->query($sql, $debug);
		$exe->run("export MOTECOM=".$config['port'].";java ".$config['MM_app']." 0 0 0");
		$sql = "update listener set PEnd = CURRENT_TIMESTAMP where PEnd is NULL";
		$result = $db->query($sql, $debug);

	}
	
	if(isset($PID) && !empty($PID))
	{		
		$sql = "update program set PStatus=2 where PStatus=4";
		$result = $db->query($sql,$debug);
		//echo $sql;
		$sql = "Update config set value= 1 where name='seqno'";
		$result = $db->query($sql, $debug);
		$sql = "select PSlot from program where PID = '$PID'";
		$result = $db->query($sql,$debug);
		$row = mysql_fetch_array($result);
		$Slot = $row['PSlot'];
		//echo $sql;
		$result = shell_exec($config['EXE_Path']." --login -c 'export MOTECOM=".$config['port'].";cd ".$config['CMD_Path']."; java GoodWindowsExec \"java ".$config['Deluge_app']. " -r -in=".$Slot." -f\"'");
		
		$sql = "update program set PStatus=4 where PID =$PID";
		$result = $db->query($sql,$debug);
		$sql = "update listener set PEnd = CURRENT_TIMESTAMP where PEnd is NULL";
		$result = $db->query($sql, $debug);
		$sql = "INSERT INTO  listener (LPID)VALUES ($PID);";
		$results = $db->query($sql, $debug);

		//echo $sql;
		$db->close();
		echo ("status=1");
		//header("Location:configure.php");
	}
	else
	{
		$sql = "Update config set value= 1 where name='seqno'";
		$result = $db->query($sql, $debug);
		$sql = "update program set PStatus=2 where PStatus =4";
		$result = $db->query($sql,$debug);
		$db->close();
		$result = shell_exec($config['EXE_Path']." --login -c 'cd ".$config['CMD_Path']."; java GoodWindowsExec \"java ".$config['Deluge_app']. " -r -in=0 -f\"'");
		echo ("status=-1");
	}
?>
</pre>
