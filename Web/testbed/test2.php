 <?php
	/*$dir = "Programs/2";

	$file = array("app.c",'main.exe',"main.ihex","main.srec","tos_image.xml");
	 
	$count = 0 ;
	$error = false;
	
	foreach (scandir($dir) as $item) 
	{
		if ($item == '.' || $item == '..') 
			continue;
		$currfile[$count] = $item;
		$count++;
    }
	//print_r($currfile);
	for($i = 0 ; $i < sizeof($file) ; $i ++)
	{
		if(!in_array($file[$i],$currfile))
		{
			$error = true;
			break;
		}
	}
	if($error)
		echo "error!!";
	*/
	mkdir("Programs/".$id,0777);
?> 