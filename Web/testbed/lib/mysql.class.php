<?php

class mysql
{

	var $server	= "localhost:3306";//database server
	var $user		= "root";        //database login name
	var $pass		= "wsnqt405";            //database login password
	var $database   = "wsnms";
		
	var $conn		= "";                  //connection 
	var $result 	= "";                  //
	

function connect() 
	{
		$this->conn = mysql_connect($this->server,$this->user,$this->pass) or die ('Error connecting to mysql<br>Server : <b>'.$this->server."</b>");
           mysql_select_db($this->database) or die("Cannot open database: <b>".$this->database."</b>");       
		
	}
	
	function close() 
	{
		mysql_close();
	}
	
	function query($query_string,$debug) 
	{
		$this->result  = mysql_query($query_string);
		if($debug && !$this->result)
			die ('Error query:<b>'.$query_string.'</b>');
		return $this->result;
	}
	
	function insert_Query($query_string) 
	{
		$this->result  =  mysql_query($query_string) ;//or die("Error insert: <b>".$query_string."</b>"); 
		
		return $this->result;
	}
	
	function begin() 
	{
		mysql_query("BEGIN");
	}
	function commit()
	{
		mysql_query("COMMIT");
	}
	function rollback()
	{
		mysql_query("ROLLBACK");
	}
}
?>
