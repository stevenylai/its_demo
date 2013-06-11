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
				$ex .=" and UDMoteID=".$chk[$i];
			else
				$ex .= " or UDMoteID=".$chk[$i];
		}
		
	$objPHPExcel = new PHPExcel();
	
	$objPHPExcel->setActiveSheetIndex(0);
	
	$db = new mysql();        
	$db->connect();
	
	$sql = "SELECT * FROM userdata where UDLID =".$_REQUEST['LID'].$ex." order by UDID DESC ";
	//$sql = "SELECT * FROM data , listener where DLID = LID and LID = ".$LID.$ex;
	$result = $db->query($sql, $debug);
	//$result = $db->query($sql, false);
	//echo $sql;
	$db->close();
	
	$objPHPExcel->setActiveSheetIndex(0);
	
	$count = 1;
	$objPHPExcel->getActiveSheet()->setCellValue('A'.$count, "No.");
	$objPHPExcel->getActiveSheet()->setCellValue('B'.$count, "Node ID");
	$objPHPExcel->getActiveSheet()->setCellValue('C'.$count, "Data1");
	$objPHPExcel->getActiveSheet()->setCellValue('D'.$count, "Data2");
	$objPHPExcel->getActiveSheet()->setCellValue('E'.$count, "Data3");
	$objPHPExcel->getActiveSheet()->setCellValue('F'.$count, "Data4");
	$objPHPExcel->getActiveSheet()->setCellValue('G'.$count, "Date");
	while($row = mysql_fetch_array($result))
	{	
		$count++;
		$objPHPExcel->getActiveSheet()->setCellValue('A'.$count, $count-1);
		$objPHPExcel->getActiveSheet()->setCellValue('B'.$count, $row['UDMoteID']);
		$objPHPExcel->getActiveSheet()->setCellValue('C'.$count, $row['UData1']);
		$objPHPExcel->getActiveSheet()->setCellValue('C'.$count, $row['UData2']);
		$objPHPExcel->getActiveSheet()->setCellValue('C'.$count, $row['UData3']);
		$objPHPExcel->getActiveSheet()->setCellValue('C'.$count, $row['UData4']);
		$objPHPExcel->getActiveSheet()->setCellValue('E'.$count, $row['UDTime']);

	}
	
	header('Content-Type: application/vnd.ms-excel');
	header('Content-Disposition: attachment;filename="export.xls"');
	header('Cache-Control: max-age=0');
	
	$objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel5');
	$objWriter->save('php://output'); 
	exit;
}

?>