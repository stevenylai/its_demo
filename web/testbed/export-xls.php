<?php
require_once './lib/PHPExcel.php';
require_once './lib/PHPExcel/IOFactory.php';
require_once './lib/mysql.class.php';

$LID = $_REQUEST['LID'];
if(isset($LID) && !empty($LID))
{
	$chk = $_REQUEST['chk_node'];
		$ex ="";
		for($i=0; $i < count($_REQUEST['chk_node']); $i++)
		{
			if($i == 0)
				$ex .=" and DMoteID=".$chk[$i];
			else
				$ex .= " or DMoteID=".$chk[$i];
		}
		
	$objPHPExcel = new PHPExcel();
	
	$objPHPExcel->setActiveSheetIndex(0);
	
	$db = new mysql();        
	$db->connect();
	
	$sql = "SELECT DTime,DpacketNum , DMoteID, DTemp, DPhoto, DLID,DpacketNum FROM `data` where DLID = ".$_REQUEST['LID'].$ex." order by DID DESC ";
	//$sql = "SELECT * FROM data , listener where DLID = LID and LID = ".$LID.$ex;
	$result = $db->query($sql, $debug);
	//$result = $db->query($sql, false);
	//echo $sql;
	$db->close();
	
	$objPHPExcel->setActiveSheetIndex(0);
	
	$count = 1;
	$objPHPExcel->getActiveSheet()->setCellValue('A'.$count, "No.");
	$objPHPExcel->getActiveSheet()->setCellValue('B'.$count, "Mote ID");
	$objPHPExcel->getActiveSheet()->setCellValue('C'.$count, "Sequence Number");
	$objPHPExcel->getActiveSheet()->setCellValue('D'.$count, "Temperature");
	$objPHPExcel->getActiveSheet()->setCellValue('E'.$count, "Light");
	$objPHPExcel->getActiveSheet()->setCellValue('F'.$count, "Time");
	
	while($row = mysql_fetch_array($result))
	{	
		$count++;
		$objPHPExcel->getActiveSheet()->setCellValue('A'.$count, $count-1);
		$objPHPExcel->getActiveSheet()->setCellValue('B'.$count, $row['DMoteID']);
		$objPHPExcel->getActiveSheet()->setCellValue('C'.$count, $row['DpacketNum']);
		$objPHPExcel->getActiveSheet()->setCellValue('D'.$count, $row['DTemp']);
		$objPHPExcel->getActiveSheet()->setCellValue('E'.$count, $row['DPhoto']);
		$objPHPExcel->getActiveSheet()->setCellValue('F'.$count, $row['DTime']);
	}
	
	header('Content-Type: application/vnd.ms-excel');
	header('Content-Disposition: attachment;filename="export.xls"');
	header('Cache-Control: max-age=0');
	
	$objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel5');
	$objWriter->save('php://output'); 
	exit;
}

?>