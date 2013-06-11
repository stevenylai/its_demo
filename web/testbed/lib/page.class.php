<?php

class page
{
	var $start =0;
	var $page =0;
	var $pages =0;
	var $per = 0; 
	var $numrows = 0;
	
	function page($num_rows,$_per){
		$this->numrows = $num_rows;
		$this->per = $_per; 
		$this->pages = ceil($num_rows/$this->per); 
		//echo "Get : ".$_GET["page"];
		if(!isset($_GET["page"])){
			$this->page=1; 
		} else {
			$this->page = intval($_GET["page"]); 
			$this->page = ($this->page > 0) ? $this->page : 1; 
			$this->page = ($this->pages > $this->page) ? $this->page : $this->pages; 
			
		}

		$this->start = ($this->page-1)*$this->per;
		//echo $this->start;
	}
	
	function getStart(){
		return $this->start;
	}
	
	function getPer()
	{
		return $this->per;
	}
	
	function showPagebar($URL)
	{
		echo "<table><tr style='background-color:#EEEEEE;'><td><b> ".$this->numrows." </b></td>";
		echo '<td><b>'.$this->page.'/'.$this->pages.'</b></td>';
		echo '<td><a href="'.$URL.'&page=1" style=\'text-decoration: none;\'> |< </a></td>';
		

		if ($this->start == 0)
		{
			echo '<td><a href="'.$URL.'&page=1" style=\'text-decoration: none;\'> < </a></td>';
		}
		else
			echo '<td><a href="'.$URL.'&page='.($this->page-1).'" style=\'text-decoration: none;\'> < </a></td>';
		

		for($i=$this->page-2;$i<=$this->page+2;$i++) {
			if ($i>0 && $i <= $this->pages)
				if($i == $this->page)
					echo '<td><b><a href="'.$URL.'&page='.$i.'" style=\'text-decoration: none;\'> ' . $i . ' </a></b></td>';
				else
					echo '<td><a href="'.$URL.'&page='.$i.'" style=\'text-decoration: none;\'> ' . $i . ' </a></td>';
		}
		
		if ($this->start >= $this->pages)
			echo '<td><a href="'.$URL.'&page='.$this->pages.'" style=\'text-decoration: none;\'> > </a></td>';
		else
			echo '<td><a href="'.$URL.'&page='.($this->page+1).'" style=\'text-decoration: none;\'> > </a></td>';
		echo '<td><a href="'.$URL.'&page='.$this->pages.'" style=\'text-decoration: none;\'> >| </a></td>';	
		
		echo "</tr></table>";

	}
}

?>