<?php
	
	
	// create the $db ojbect
	$db = new mysql();
	
	// connect to the server
	$db->connect();
	
	$str 	= $_REQUEST['par'];
	//get the number of attribute

//	$result = $db->query("SELECT * FROM user join ans_log on user.netid = ans_log.ans_netid where ".str_replace("\'","'",$str));
	$sql="SELECT distinct  user.*, ans_log.* FROM user left join student on user.netid=student.student_netid inner join ans_log on user.netid = ans_log.ans_netid where  ".str_replace("\'","'",$str);
	$result = $db->query($sql);
	$num_rows = mysql_num_rows($result);
	 
	echo ($num_rows);
//echo ("SELECT * FROM user join ans_log on user.netid = ans_log.ans_netid where ".str_replace("\'","'",$str));
	 $db->close();
?>
