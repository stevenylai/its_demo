<?php
  include('pclzip.lib.php');
  $archive = new PclZip('pclzip-2-8-2.zip');
  if ($archive->extract(PCLZIP_OPT_PATH, '.')) { /*data換成其他路徑即可*/
    die("Error : ".$archive->errorInfo(true));
  }
?>
