<?php
	session_start();
	
	if(isset($_SESSION['login']['status']) && $_SESSION['login']['status'] == 1)
	{
		
		echo "<script>window.location = 'configure.php'</script>";
	
	}
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>WSN-Based Traffic Information System</title>
<meta http-equiv="Content-Language" content="English" />
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="css/style.css" media="screen" />

</head>
<body>
<div id="wrap">

<div id="top"></div>

<div id="content">

<div class="header">
<h1><a href="#">WSN-Based Traffic Information System </a></h1>
<h2>&nbsp;</h2>
</div>


<div class="content" style=" text-align:center">
	<center>
	<form action="dblogin.php" method="post"> 
		
		<table border="0" cellspacing="10">
			<tr>
				<th colspan="2">Log In </th>
			</tr>
			<tr>
				<td>User Name:</td>
				<td><input type="text" name="txt_UName" id="txt_UName"  /></td>
			</tr>
			<tr>
				<td>Password:</td>
				<td><input type="password" name="txt_Pass" id="txt_Pass" /> </td>
			</tr>
			<tr>
				<td><input type="submit" id="btn_submit" value="Submit"/></td>
				<td><input type="reset" id="btn_reset" value="Reset"/></td>
			</tr>
			<tr><td colspan="2"><samp id='msg' style="color:red; font-weight:bold; display:<?=(isset($_REQUEST['status'])&&$_REQUEST['status']==1?'block':'none')?>;">Invalid user name or password!</samp></td></tr>
			<!--<tr><td><a href="dbsignup.php">Sign Up</a></td><td><a href="FPassword.php">Forget password?</a></td></tr>-->
		</table>
	</form>	
	</center>	
</div>

<div id="clear"></div>

</div>

<div id="bottom"></div>

</div>

<div id="footer">
 <!--<a href="www.comp.polyu.edu.hk">Polyu</a></div>-->

</body>
</html>