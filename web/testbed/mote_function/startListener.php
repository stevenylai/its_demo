 <?php
	//set_time_limit(0);
	include_once('../config/config.php');
	include_once('../lib/mysql.class.php');
	include_once('../lib/process.class.php');
	$debug = true;
	$db = new mysql();        
	$db->connect();
	
	$PID = $_REQUEST['PID'];
	
	$sql = "select * from config where name = 'LisPID'";
	$result = $db->query($sql, $debug);
	$row = mysql_fetch_array($result);
 //echo $row['value'];
 	if($row['value'] == 0)
	{
	    if(!isset($_REQUEST['interval']) || !is_numeric($interval))
			$interval = 1000;
		$exe = new exeC();
		$LPID = $exe->run("export MOTECOM=".$config['port'].";java ".$config['MM_app']." 1 ".mysql_insert_id()." ".$interval);
		//echo "java net.tinyos.app.MainClass 1 ".mysql_insert_id()." ".$interval;

		$sql = "update config set value = '".$LPID."'  where name = 'LisPID'";
		$result = $db->query($sql, $debug);
		
		echo "1";
		//echo "<script>document.location = \"../network.php?par=1\";</script>";
	}
	else
	{
		echo "2";
		//echo "<script>document.location = \"../network.php?par=0\";</script>";
	}
	//echo "3";
	$db->close();
	

 
   //header("Location:network.php");
?> 