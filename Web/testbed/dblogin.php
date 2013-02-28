<?php
	session_start();
	include_once('./lib/mysql.class.php');
	
	//session_destroy();
	session_unset(); 
	
	$debuge = 0;
	
	$user = $_REQUEST['txt_UName'];
	$pwd = $_REQUEST['txt_Pass'];

	$db = new mysql();        
	$db->connect();

	$sql = "select UID,UType from user where ULoginName = '$user' and UPwd = PASSWORD('".$pwd."')";
	
	$result = $db->query($sql,$debug);
	
	if(!$result || mysql_num_rows($result)==0)
	{
		$db->close();
		header("Location:index.php?status=1");
	}
	else
	{
		$row = mysql_fetch_array($result);
		$db->close();
		
		$_SESSION['user']['id'] = $row['UID'];
		$_SESSION['user']['type'] = $row['UType'];
		$_SESSION['login']['status'] = 1;
			
		header("Location:configure.php");
	}
?>