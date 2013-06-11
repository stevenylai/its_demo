<?php
session_start();

if(!isset($_SESSION['login']['status']) || $_SESSION['login']['status'] != 1)
	echo "<script>window.location = 'index.php'</script>";

?>
