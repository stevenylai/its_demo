<?php   
header('Content-type: text/xml');
//set_time_limit(0);
session_start();
include_once('../lib/mysql.class.php');
$db = new mysql();        
$db->connect();


$category ="";
$numId = $_REQUEST['numid'];
if($_SESSION[NodeNum]<0)
{
	$sql = "select DISTINCT DMoteID from listener, data where LID =".$_REQUEST['LID']." and LID = DLID limit 5";
}
else
{
	$sql = "select DISTINCT DMoteID from listener, data where LID =".$_REQUEST['LID']." and LID = DLID ";
	$ex = "";
	//echo "SESSION[mid]:".$_SESSION["mid0"];
	for($i=0; $i < $_SESSION['NodeNum']; $i++)
	{
		if($i == 0)
		{
			$ex .=" and DMoteID=".$_SESSION["mid".$i];
		}
		else
		{
			$ex .=" or DMoteID=".$_SESSION['mid'.$i];
		}
		
		unset($_SESSION['mid'.$i]);
	}
	$sql .=$ex;
	//echo $sql;
}
unset($_SESSION['num']);
$result = $db->query($sql, true);
$i = 0;
$num=mysql_num_rows($result);
while($row = mysql_fetch_array($result))
{
	//echo "1i:<p>";
	$temp[$row['DMoteID']] = '';
	$arr[$i] = $row['DMoteID'];
	$i++;
}

function addSecondsToTimestamp ($_timestamp, $_amount) {
    list($year, $month, $day, $hours, $minutes, $seconds) = preg_split('/[- :]/', $_timestamp);
    return date('Y-m-d H:i:s', mktime($hours, $minutes, $seconds + $_amount, $month, $day, $year));
}



$sql = "select Max(PEnd) as max, Min(PStart) as min, now() as now  from listener, data where LID =".$_REQUEST['LID']." and LID = DLID";


$result = $db->query($sql, true);
$i = 0;
$row = mysql_fetch_array($result);

if($row['max']!=NULL)
	$max = $row['max'];
else
	$max = $row['now'];
$min = $row['min'];
list($maxyear, $maxmonth, $maxday, $maxhours, $maxminutes, $maxseconds) = preg_split('/[- :]/', $max);
list($minyear, $minmonth, $minday, $minhours, $minminutes, $minseconds) = preg_split('/[- :]/', $min);
$interval=1;
if($maxyear-$minyear > 10)
	$interval=60 * 60 * 24 * 365;
elseif($maxmonth-$minmonth > 10)
	$interval=60 * 60 * 24 * 30;
elseif($maxday-$minday > 10)
	$interval=60 * 60 * 24;
elseif($maxhours-$minhours > 10)
	$interval=60 * 60;
elseif($maxminutes-$minminutes > 10)
	$interval=60;
elseif($maxseconds-$minseconds > 10)
	$interval=30;
	
$time = $min;
$amax =0;
$amin = 99999999;

//$num = 1;
do
{
	$sql ="select AVG(DPhoto) as avg, DMoteID from listener, data where LID =".$_REQUEST['LID']." and LID = DLID and Dtime>'$time' and Dtime<='".addSecondsToTimestamp($time,$interval)."' group by DMoteID ";
	$result = $db->query($sql, true);
	
	for($i = 0 ; $i<$num ; $i++)
	{
		
		
		//echo $sql."<p>";
		/*if(mysql_num_rows($result)==0) 
		{
			$category .="<category label='' />";
			for($k = 0 ; $k<sizeof($arr) ; $k++) 
			$temp[$arr[$k]] .= "<set value='' />";
		}*/
		$tmp = 0;
		while($row = mysql_fetch_array($result))
		{
			
			if(mysql_num_rows($result)>0) 
			{
				if($tmp ==0)
					$category .="<category label='".$time."' />";
				$temp[$row['DMoteID']] .= "<set value='".(int)$row['avg']."' />";
				if($amax <(int)$row['avg'])
					$amax = (int)$row['avg'];
				if($amin >(int)$row['avg'])
					$amin = (int)$row['avg'];
			}
			else
			{
				if($tmp ==0)
					$category .="<category label='' />";
				$temp[$row['DMoteID']] .= "<set value='' />";
			}
			$tmp ++;
		}	
	}
	$time = addSecondsToTimestamp($time,$interval);
} while($time < $max);

$strXML ="<chart caption='Light' subCaption='' numdivlines='9' lineThickness='2' showValues='0' anchorRadius='3' anchorBgAlpha='50' formatNumberScale='0' labelStep='4'  labelDisplay='WRAP' yAxisMinValue='".((int)($amin-$amin/100*20))."' yAxisMaxValue='".((int)($amax+$amax/100*20))."'  showAlternateVGridColor='1' numVisiblePlot='12' animation='0'>";
$strXML .="<categories >";
$strXML .=$category ;
$strXML .="</categories>";
$color[1] = 800080;
$color[2] = 991100;
$color[3] = 089980;
$color[4] = 999980;
$color[5] = 009999;

for($i = 0 ; $i < sizeof($arr) ; $i++)
{
	$strXML .="<dataset seriesName='".$arr[$i]."' color='".$color[$i]."' anchorBorderColor='".$color[$i]."'>";
    $strXML .= $temp[$arr[$i]];
	$strXML .="</dataset>";
}

$strXML .="</chart>";
echo $strXML;
$db->close();
?>
