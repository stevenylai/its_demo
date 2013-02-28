<?php
	session_start();
	include_once('./lib/mysql.class.php');
	
	$debuge = 0;
	
	$uid = $_REQUEST['UID'];
	
	$db = new mysql();        
	$db->connect();

	$sql = "Delete from user where UID = '$uid'";
	
	$result = $db->query($sql,$debug);
	
	/*if(!$result || mysql_num_rows($result)==0)
	{
		$db->close();
		header("Location:index.php?status=1");
	}
	else
	{
		$row = mysql_fetch_array($result);
		$db->close();
		
		
		$_SESSION['user']['id'] = $row['UID'];
		$_SESSION['login']['status'] = 1;
		
			
		header("Location:configure.php");
	}*/
	header("Location:User_UM.php");
?>