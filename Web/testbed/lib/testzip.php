<?php
  include('pclzip.lib.php');
  $archive = new PclZip('pclzip-2-8-2.zip');
  if ($archive->extract(PCLZIP_OPT_PATH, '.')) { /*data������L���|�Y�i*/
    die("Error : ".$archive->errorInfo(true));
  }
?>
