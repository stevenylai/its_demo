<?php
	session_start();
	include_once('./lib/mysql.class.php');
	include_once('./lib/pclzip.lib.php');
	
	$debug = true;
	$Name = $_REQUEST['txt_pname'];
	$Slot = $_REQUEST['s'];
	
	$db = new mysql();        
	$db->connect();
	
	$sql = "select * from program where PStatus != 3 and PUID = ".$_SESSION['user']['id']." and PSlot = ".$Slot;
	$result = $db->query($sql,$debug);
	//echo "$sql";
	if(mysql_num_rows($result) == 0)
	{
		$sql = "SHOW TABLE STATUS LIKE 'program'";
		$result = $db->query($sql,$debug);
		$rows = mysql_fetch_assoc($result);
		$id = $rows['Auto_increment'];
		$db->close();
		
		mkdir("Programs/".$id,0777);
		
		$root = "Programs/".$id."/";
		$target_path = $root.$_FILES['uploadedfile']['name']; 
		
		
		
		$limit_size=10000;
		$file_size = $FILES['uploadedfile']['size'];
		
		if($file_size > $limit_size)
		{
			echo "<script>alert('Your file size is over limit');location.href='User_pro.php';</script>";
		}
		else
		{
			
			if(move_uploaded_file($_FILES['uploadedfile']['tmp_name'], $target_path))
			{
			
				$ext = split('[.]', $_FILES['uploadedfile']['name']);
			
				if($ext[sizeof($ext)-1] == "zip")
				{
					$archive = new PclZip($target_path);
					if ($archive->extract(PCLZIP_OPT_PATH, $root) )
					{ 
				
						unlink($target_path);
						
						$db->connect();
						
						
						$file = array("app.c",'main.exe',"main.ihex","main.srec","tos_image.xml");
						
						$count = 0 ;
						$error = false;
						
						foreach (scandir($root) as $item) 
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
							$sql = "INSERT INTO  program (PID ,PName ,PPath ,PUID ,PSlot,PDate,PStatus)VALUES (NULL , '$Name',  '$root',  '".$_SESSION['user']['id']."',".$Slot.", NOW(),0)";
						else
							$sql = "INSERT INTO  program (PID ,PName ,PPath ,PUID ,PSlot,PDate,PStatus )VALUES (NULL , '$Name',  '$root',  '".$_SESSION['user']['id']."', ".$Slot.",NOW(),1)";
						$result = $db->query($sql,$debug);
						$db->close();
						
						echo "<script>alert('The file has been uploaded');location.href='User_pro.php';</script>";
					} 
					else 
					{
						echo "<script>alert('File extraction error!!');location.href='User_pro.php';</script>";
					}// end if
				}// end if 
			} else{
			
				switch ($_FILES['uploadFile'] ['error'])
				{  
					case 1:
						echo "<script>alert('The file is bigger than this PHP installation allow!');location.href='User_pro.php';</script>";
						break;
					case 2:
						echo "<script>alert('The file is bigger than this form allows!');location.href='User_pro.php';</script>";
						break;
					case 3:
						echo "<script>alert('Only part of the file was uploaded');location.href='User_pro.php';</script>";
						break;
					case 4:
						echo "<script>alert('No file was uploaded');location.href='User_pro.php';</script>";
						break;
				}//END switch
			}//end if
			
		}
	}
	else
	{
		echo "<script>alert('There was an error uploading the file, please try again!');location.href='User_pro.php';</script>";

	}
		
	
?>