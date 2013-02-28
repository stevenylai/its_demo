<?php
	include_once('../lib/mysql.class.php');
	session_start();
	$db = new mysql();        
	$db->connect();
	$debug = true;
	$LID = $_SESSION[LID];
	$NID = $_REQUEST['i'];
	//echo "iiiii:".$NID;
	//unset($_SESSION[LID]);
	
	$sql = "select PStart, PEnd from listener where LID =".$LID;
	$result = $db->query($sql,$debug);
	$row = mysql_fetch_array($result);
	$Start = $row['PStart'];
//	echo "END: ".$row['PEnd'];
	if($row['PEnd']==NULL)
	{
		$sql = "select TIMESTAMPDIFF(second,PStart,now()) as time, now() as end from listener where LID =".$LID;
		$result = $db->query($sql,$debug);
		$row = mysql_fetch_array($result);
		$end =  $row['end'];
		$total = $row['time'];
	}
	else
	{
		$sql = "select TIMESTAMPDIFF(second,PStart,PEnd) as time, PEnd from listener where LID =".$LID;
		$result = $db->query($sql,$debug);
		$row = mysql_fetch_array($result);
		$end =  $row['PEnd'];
		$total = $row['time'];

	}
	//echo "<p>$total</p>";
	//else
		//$End = $row['PEnd'];
		
	$sql = "select * from nodelog where NLNID = ".$_SESSION["mid".$NID]." and NLLID=".$LID." and NLtype = 1 group by NLDate order by NLDate";
	$result = $db->query($sql,$debug);
	//echo "sql:$sql<p>";
	
	$tmp = -1;
	$sleepTime=0;
	$i=0;
	$num = mysql_num_rows($result);
	while($row = mysql_fetch_array($result))
	{
		$i++;
		if($tmp==-1)
		{
			if($row['NLStatus']==2)
			{
				//select TIMESTAMPDIFF(second,'2010-04-12 17:27:27','2010-04-12 12:16:12') as time
				$sql = "select TIMESTAMPDIFF(second,'".$Start."','".$row['NLDate']."') as time";
				//echo "1".$sql."<br>";
				$result2 = $db->query($sql,$debug);
				$row2 = mysql_fetch_array($result2);
				$sleepTime = $row2['time'];
				//$tmp = $row['NLDate'];
				//echo "<p>tmp:$sleepTime</p>";
			}
			$tmp = $row['NLDate'];
		}
		else
		{
			if($row['NLStatus']==1 && $tmpStstus ==2)
			{
				$sql = "select TIMESTAMPDIFF(second,'".$tmp."','".$row['NLDate']."') as time";
				//echo "2".$sql."<br>";
				$result2 = $db->query($sql,$debug);
				$row2 = mysql_fetch_array($result2);
				$sleepTime += $row2['time'];
				
				//echo "<p>tmp:$sleepTime</p>";
			}
			
			if($num == $i && $row['NLStatus']==2)
			{
				$sql = "select TIMESTAMPDIFF(second,'".$row['NLDate']."','".$end."') as time from listener where LID =".$LID;
				//echo "3".$sql."<br>";
				$result2 = $db->query($sql,$debug);
				$row2 = mysql_fetch_array($result2);
				$sleepTime += $row2['time'];
				//$tmp = $row['NLDate'];
				//echo "<p>tmp:$sleepTime</p>";
			}
			$tmpStstus = $row['NLStatus'];
			$tmp = $row['NLDate'];
		}
		
		
	}
	$db->close();
	//echo "<p>sleepTime:$sleepTime</p>";
	//echo "<p>total:$total</p>";
include 'ofc-library/open-flash-chart.php';

$title = new title( "Node ".$_SESSION["mid".$NID].' : Sleeping Time(pre second)' );

$pie = new pie();
$pie->set_alpha(0.6);
$pie->set_start_angle( 35 );
$pie->add_animation( new pie_fade() );
$pie->set_tooltip( '#val# of #total#<br>#percent# of 100%' );
$pie->set_colours( array('#1C9E05','#FF368D') );
$pie->set_values( array(new pie_value($sleepTime, "Sleeping"),new pie_value(($total-$sleepTime), "processing")) );

$chart = new open_flash_chart();
$chart->set_title( $title );
$chart->add_element( $pie );


$chart->x_axis = null;

echo $chart->toPrettyString();
unset($_SESSION["mid".$NID]);

?>