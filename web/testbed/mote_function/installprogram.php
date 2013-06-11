<?php
	//session_start();
	set_time_limit(0);
	include_once('../lib/mysql.class.php');
	include_once('../lib/process.class.php');
	include_once('../config/config.php');
?>
<pre>
<?php
	$debug = true;
	$PID = $_REQUEST['PID'];
	$Slot = $_REQUEST['Slot'];
	//echo $PID ;
	//echo $Slot ;

	$db = new mysql();        
	$db->connect();
	

	if(isset($PID) && isset($Slot) && !empty($PID) && !empty($Slot))
	{
		//echo "s";
		$exe = new exeC();
		
		$sql = "update config set value=0 where name = 'injectStatus'";
		$result = $db->query($sql,$debug);
		$sql = "update config set value='' where name = 'injectMsg'";
		$result = $db->query($sql,$debug);

		
		$PPID = $exe->run("export MOTECOM=".$config['port'].";cd ".$config['Program_Path'].$PID.";java ".$config['Deluge_app']. " -i -f --tosimage=tos_image.xml -in=".$Slot);
		//$PPID = $exe->run("ls");
		echo "export MOTECOM=".$config['port'].";cd ".$config['Program_Path'].$PID.";java ".$config['Deluge_app']. " -i -f --tosimage=tos_image.xml -in=".$Slot;
		echo "<p>".$PPID;
		
		
		$sql = "update config set value = '".$PPID."' where name = 'injectPID'";
		$result = $db->query($sql,$debug);
		$sql = "update config set value = '".$PID."' where name = 'injectProgram'";
		$result = $db->query($sql,$debug);
		
	
		//print($result);
		//header("Location:configure.php");
	}
	$db->close();
?>
</pre>
