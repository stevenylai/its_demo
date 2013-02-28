<?php

include 'ofc-library/open-flash-chart.php';

$tmp = 4000;
$data = array();

for( $i=0; $i<5; $i++ )
{

	$tmp = $tmp -rand(200,800);
	if($tmp > 0)
 		$data[$i] = $tmp;
	else
 		$data[$i] = 0;
}

$tmp = 4000;
$data2 = array();
for( $i=0; $i<5; $i++ )
{
	$tmp = $tmp -rand(200,800);
	if($tmp > 0)
 		$data2[$i] = $tmp;
	else
 		$data2[$i] = 0;
}

$tmp = 4000;
$data3 = array();
for( $i=0; $i<5; $i++ )
{
	$tmp = $tmp -rand(200,800);
	if($tmp > 0)
 		$data3[$i] = $tmp;
	else
 		$data3[$i] = 0;
}

$chart = new open_flash_chart();

$title = new title("Energy Consumption" );
$title->set_style( '{font-size: 24px; color: #555555}' );

$d = new solid_dot();
$d->size(3)->halo_size(1)->colour('#3D5C56');

$line = new line();
$line->set_default_dot_style($d);
$line->set_values( $data );
$line->set_width( 2 );
$line->set_colour( '#3D5C56' );
$line->set_key( 'Node 1', 12);

$d2 = new solid_dot();
$d2->size(3)->halo_size(1)->colour('#FF0000');
$line2 = new line();
$line2->set_default_dot_style($d2);
$line2->set_values( $data2 );
$line2->set_width( 2 );
$line2->set_colour( '#FF0000' );
$line2->set_key( 'Node 2', 12);

$d3 = new solid_dot();
$d3->size(3)->halo_size(1)->colour('#11dd11');
$line3 = new line();
$line3->set_default_dot_style($d3);
$line3->set_values( $data3 );
$line3->set_width( 2 );
$line3->set_colour( '#11dd11' );
$line3->set_key( 'Node 3', 12);
/*
$area1 = new area();
$area1->set_colour( '#3D5C56' );
$area1->set_key( 'Node 1', 12);
$area2 = new area();
$area2->set_key( 'Node 2', 12);
$area3 = new area();
$area3->set_key( 'Node 3', 12);*/

$x_legend = new x_legend( 'T(50s)' );
$x_legend->set_style( '{font-size: 16px; color: #778877}' );

$y_legend = new y_legend( 'BatteryVoltage' );
$y_legend->set_style( '{font-size: 16px; color: #778877}' );


$y = new y_axis();
$y->set_range( 0, 4500, 500 );

$x = new x_axis();
$x->set_range( 1,6,1 );



$chart->set_title( $title );
$chart->add_element( $line );
$chart->add_element( $line2 );
$chart->add_element( $line3 );
$chart->set_y_axis( $y );
$chart->set_x_axis( $x );
$chart->set_x_legend( $x_legend );
$chart->set_y_legend( $y_legend );


/*$chart->add_element( $area1 );
$chart->add_element( $area2 );
$chart->add_element( $area3 );
*/
echo $chart->toPrettyString();
?>