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
				$ex .=" and NLNID=".$chk[$i];
			else
				$ex .= " or NLNID=".$chk[$i];
		}
		
	$objPHPExcel = new PHPExcel();
	
	$objPHPExcel->setActiveSheetIndex(0);
	
	$db = new mysql();        
	$db->connect();
	
	$sql = "SELECT * FROM nodelog where NLLID =".$_REQUEST['LID'].$ex." order by NLID DESC ";
	//$sql = "SELECT * FROM data , listener where DLID = LID and LID = ".$LID.$ex;
	$result = $db->query($sql, $debug);
	//$result = $db->query($sql, false);
	//echo $sql;
	$db->close();
	
	$objPHPExcel->setActiveSheetIndex(0);
	
	$count = 1;
	$objPHPExcel->getActiveSheet()->setCellValue('A'.$count, "No.");
	$objPHPExcel->getActiveSheet()->setCellValue('B'.$count, "Node ID");
	$objPHPExcel->getActiveSheet()->setCellValue('C'.$count, "Type");
	$objPHPExcel->getActiveSheet()->setCellValue('D'.$count, "Status");
	$objPHPExcel->getActiveSheet()->setCellValue('E'.$count, "Date");
	while($row = mysql_fetch_array($result))
	{	
		$count++;
		$objPHPExcel->getActiveSheet()->setCellValue('A'.$count, $count-1);
		$objPHPExcel->getActiveSheet()->setCellValue('B'.$count, $row['NLNID']);
		switch ($row['NLTYPE'])
		{
			case 1:
				//echo "<td align='center'>Sensor Status</td>";
				$objPHPExcel->getActiveSheet()->setCellValue('C'.$count, "Sensor Status");
				break;
			default:
				$objPHPExcel->getActiveSheet()->setCellValue('C'.$count,$row['NLTYPE']);
				
		}
		switch ($row['NLTYPE'])
		{
			case 1:
				if($row['NLStatus'] == 1)
					//echo "<td align='center'>Activative</td>";
					$objPHPExcel->getActiveSheet()->setCellValue('D'.$count, "Activative");
				else
					//echo "<td align='center'>Deactivative</td>";
					$objPHPExcel->getActiveSheet()->setCellValue('D'.$count, "Deactivative");
				break;
			default:
				$objPHPExcel->getActiveSheet()->setCellValue('D'.$count, $row['NLStatus']);
				
		}
		
		
		$objPHPExcel->getActiveSheet()->setCellValue('E'.$count, $row['NLDate']);

	}
	
	header('Content-Type: application/vnd.ms-excel');
	header('Content-Disposition: attachment;filename="export.xls"');
	header('Cache-Control: max-age=0');
	
	$objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel5');
	$objWriter->save('php://output'); 
	exit;
}

?>