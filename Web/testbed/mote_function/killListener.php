 <?php
	//set_time_limit(0);
	
	include_once('../lib/mysql.class.php');
	include_once('../lib/process.class.php');
	include_once('../config/config.php');
	$debug = true;
	$db = new mysql();        
	$db->connect();

	$sql = "select * from config where name = 'LisPID'";
	$result = $db->query($sql, $debug);
	$row = mysql_fetch_array($result);
	
	$exe = new exeC();
	//echo "export MOTECOM=".$config['port'].";java ".$config['MM_app']." 0 0 0";
	if($row['value'] != 0 && $exe->kill($row['value']))
	{
		$sql = "update config set value = 0 where name = 'LisPID'";
		$result = $db->query($sql, $debug);
		$exe->run("export MOTECOM=".$config['port'].";java ".$config['MM_app']." 0 0 0");
		
		//$sql = "update listener set PEnd = CURRENT_TIMESTAMP where PEnd is NULL";
		//$result = $db->query($sql, $debug);
		echo("&par=1");
		//echo "<script>document.location = \"../network.php?par=1\";</script>";
	}
	else
	{
		echo("&par=0");
		//echo "<script>document.location = \"../network.php?par=0\";</script>";
	
	}
	$db->close();
	//echo "<script>document.location = \"../network.php\";</script>"

	//header("Location:network.php");
   
   
?> 