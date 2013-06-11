<?php
	session_start();
	set_time_limit(0);
	include_once('../lib/mysql.class.php');
	include_once('../lib/process.class.php');
	include_once('../config/config.php');
	
	$db = new mysql();        
	$db->connect();
	
	$sql = "select * from program where PID=".$_REQUEST['txt_PID'];
	$result = $db->query($sql,$debug);
	$row = mysql_fetch_array($result);
	deleteDirectory($row['PPath']);
	
	switch ($row['PStatus'])
	{
		case 4:
			$sql = "select * from config where name = 'LisPID'";
			$result = $db->query($sql, $debug);
			$row = mysql_fetch_array($result);	
			$exe = new exeC();
			if($row['value'] != 0 && $exe->kill($row['value']))
			{
				$sql = "update config set value = 0 where name = 'LisPID'";
				$result = $db->query($sql, $debug);
				$exe->run("export MOTECOM=".$config['port'].";java ".$config['MM_app']." 0 0 0");

				$sql = "update listener set PEnd = CURRENT_TIMESTAMP where PEnd is NULL";
				$result = $db->query($sql, $debug);
			}
		case 2:
			//$result = shell_exec("C:\\tinyos\cygwin\bin\bash.exe --login -c 'cd /home/garytsoi; java GoodWindowsExec \"java net.tinyos.tools.Deluge_WSNMS -r -in=0 -f\"'");
			//$result = shell_exec($config['EXE_Path']." --login -c 'export MOTECOM=".$config['port'].";cd ".$config['CMD_Path']."; java GoodWindowsExec \"java ".$config['Deluge_app']. " -r -in=".$Slot." -f\"'");
			$result = shell_exec($config['EXE_Path']." --login -c 'export MOTECOM=".$config['port'].";cd ".$config['CMD_Path']."; java GoodWindowsExec \"java ".$config['Deluge_app']. " -e -in=".$row['PSlot']." -f\"'");
			break;
		
			
	}
	
	//$sql = "delete from program where PID=".$_REQUEST['txt_PID'];
	//$sql = "delete from program where PID=".$_REQUEST['txt_PID'];
	$sql = "update program set PStatus=3 where PID = ".$_REQUEST['txt_PID'];
	$result = $db->query($sql,$debug);
	
	$db->close();
	
	

	/*echo "<script>location.href='User_pro.php';</script>";
    */
	
	function deleteDirectory($dir) {
        if (!file_exists($dir)) return true;
        if (!is_dir($dir)) return unlink($dir);
        foreach (scandir($dir) as $item) {
            if ($item == '.' || $item == '..') continue;
            if (!deleteDirectory($dir.DIRECTORY_SEPARATOR.$item)) return false;
        }
        return rmdir($dir);
    }
	
	print("1");
?>