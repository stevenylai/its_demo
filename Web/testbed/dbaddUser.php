<?php
	include_once('./lib/mysql.class.php');
	
	$debug = false;
	
	$LIname = $_REQUEST['LIname'];
	$pwd = $_REQUEST['pwd'];
	$Fname = $_REQUEST['Fname'];
	$Lname = $_REQUEST['Lname'];
	$Email = $_REQUEST['Email'];
	$role = $_REQUEST['role'];
	
	$db = new mysql();        
	$db->connect();

	$sql = "select UID from user where ULoginName = '$name'";
	//echo "$sql";
	$result = $db->query($sql,$debug);
	
	if(mysql_num_rows($result)==0)
	{
		$sql = "INSERT INTO  user(ULoginName ,UPwd ,UEmail ,UFName ,ULName ,UType)VALUES ('".mysql_escape_string($LIname)."',  PASSWORD('".mysql_escape_string($pwd)."'),  '$Email',  '$Fname',  '$Lname',  $role)";
		 
		$result = $db->query($sql,$debug);
		$db->close();
		header("Location:User_UM.php");
	}
	echo "<script>alert('Try Again!!')</script>";
	/*else
	{
		$row = mysql_fetch_array($result);
		$db->close();
		
		
		$_SESSION['user']['id'] = $row['UID'];
		$_SESSION['login']['status'] = 1;
		
			
		header("Location:configure.php");
	}*/
	echo "<script>location.href ='User_UM.php'</script>";
?>