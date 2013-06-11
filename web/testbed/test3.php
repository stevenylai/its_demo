 <?php
	set_time_limit(0);
	
	//$result = shell_exec("C:\\tinyos\cygwin\bin\bash.exe --login -c 'cd /home/garytsoi; java GoodWindowsExec \"cd /opt/tinyos-2.x/apps/Blink/;make micaz\"' & $!");
	//$result = shell_exec("C:\\tinyos\cygwin\bin\bash.exe --login -c 'cd /home/garytsoi; java GoodWindowsExec \"ps\" &' ");
	//$result = shell_exec("C:\\tinyos\cygwin\bin\bash.exe --login -c 'cd /home/garytsoi; java GoodWindowsExec \"ps > /dev/null & echo $!\"' ");
	//printf("result: ".$result);
	
	function background($Command, $Priority = 0){
       if($Priority)
           $PID = shell_exec("C:\\tinyos\cygwin\bin\bash.exe --login -c 'nohup nice -n $Priority $Command > /dev/null & echo $!'");
       else
           $PID = shell_exec("C:\\tinyos\cygwin\bin\bash.exe --login -c \"nohup $Command > /dev/null & echo $!\"");
       return($PID);
   }
   function is_process_running($PID)
    {
        exec("C:\\tinyos\cygwin\bin\bash.exe --login -c \"ps $PID\"", $ProcessState);
        return(count($ProcessState) >= 2);
    }
	
	
	$CopyTaskPid = background("java net.tinyos.tools.Listen");
	echo "<p>$CopyTaskPid</p>";
   
   
?> 