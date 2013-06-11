<?php
session_start();
include 'ofc-library/open-flash-chart.php';
include_once('../lib/mysql.class.php');

$LID = $_REQUEST['LID'];
$chk = $_REQUEST['chk_node'];
$ex = "";
$debug = true;



$db = new mysql(); 
$db->connect();
//$sql = "Select * from listener where LID =".$LID ;
//echo $sql."<p>";
//$result = $db->query($sql, $debug);
//echo "NodeNum: ".$_SESSION[NodeNum];
if($_SESSION[NodeNum]<0)
{
	//echo "ss1";
	$sql = "SELECT DISTINCT DMoteID FROM data where DLID =".$LID." order by DMoteID limit 5" ;
}
else
{
	//echo "ss2";
	$sql = "SELECT DISTINCT DMoteID FROM data where DLID =".$LID ;
	for($i=0; $i < $_SESSION['NodeNum']; $i++)
	{
		//echo $chk[$i]."<p>";
		//$str_chk .= " chk_node[] = ".$chk[$i];
		//echo "mid".$_SESSION["NodeNum".$i];
		if($i == 0)
		{
			$sql .=" and DMoteID=".$_SESSION["mid".$i];
		}
		else
		{
			$sql .=" or DMoteID=".$_SESSION['mid'.$i];
		}
		unset($_SESSION['mid'.$i]);
	}
	//$sql .=" order by DMoteID" ;
	//echo $sql."<br />";
	//$sql = "SELECT DISTINCT DMoteID FROM data where DLID =1 and DMoteID=12 order by DMoteID";
	//echo $sql."<br/>";
}
unset($_SESSION['num']);

$result = $db->query($sql, $debug);

$i = 0;
while($row = mysql_fetch_array($result))
{
	//echo $row['DMoteID']."<p>";
	$ID[$i] = $row['DMoteID'];
	$Loss[$i] = 0;
	$sql = "SELECT `DpacketNum` FROM `data` where DLID =".$LID." and DMoteID =".$ID[$i]." order by `DID`";
	//echo "$sql<p>";
	$result2 = $db->query($sql, $debug);
	$count = 1;
	while($row2 = mysql_fetch_array($result2))
	{
		//echo "data:".$row2['DpacketNum'] ."<br />";
		if($row2['DpacketNum'] == $count)
		{
			//echo "1<br />";
			$count++;
			if($count > 65534)
				$count = 1;
		}
		else
		{
			do 
			{
				if($count > 65534)
					$count = 1;
				$Loss[$i]++;
				//$count++;
			}while($count++ != $row2['DpacketNum']);
		}
	}
	//echo "Loss".$Loss[$i]."<p>";
	$i++;
}

//print_r($i);

$db->close();

$title = new title( "Packet Loss" );
$title->set_style( '{font-size: 24px; color: #555555}' );


$bar = new bar_filled( '#E2D66A', '#577261' );
$bar->set_values( $Loss );

$x = new x_axis();
$x->set_labels_from_array($ID);
//print_r($Loss);

if(max($Loss) > 0)
{
	$y = new y_axis();
	if(max($Loss) < 20)
		$y->set_range( 0, 20, 5);
	elseif(max($Loss) < 50)
		$y->set_range( 0, 50, 10);
	elseif(max($Loss) < 100)
			$y->set_range( 0, 100, 25);
		elseif(max($Loss) < 500)
				$y->set_range( 0, 500, 100);
			else
				$y->set_range( 0, max($Loss)+max($Loss)*0.1, max($Loss)/10);
}
	
$chart = new open_flash_chart();
$chart->set_title( $title );
$chart->add_element( $bar );
$chart->set_x_axis( $x );
$chart->set_y_axis( $y );
$chart->set_bg_colour( '#FFFFFF' );


echo $chart->toPrettyString();
?>