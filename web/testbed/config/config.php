<?php
	$configFile = '../config/config.txt';

	$config = array();

	$fh = fopen( $configFile, 'r' );
	while( $l = fgets( $fh ) )
	{
	  if ( preg_match( '/^#/', $l ) == false )
	  {
		preg_match( '/^(.*?)=(.*?)$/', $l, $found );
		$config[ $found[1] ] = $found[2];
	  }
	}
	fclose( $fh );
	//print_r($config);
?>