<?php
class exeC {
    /**
     * Run Application in background
     *
     * @param     unknown_type $Command
     * @param     unknown_type $Priority
     * @return     PID
     */
    function run($Command, $Priority = 0){
       if($Priority)
           $PID = shell_exec("\"C:/Program Files/Programming/cygwin/bin/bash.exe\" --login -c 'nohup nice -n $Priority $Command > /dev/null & echo $!'");
       else
	   {
           $PID = shell_exec("\"C:/Program Files/Programming/cygwin/bin/bash.exe\" --login -c \"$Command > /dev/null & echo $!\"");
		   //$PID = shell_exec("C:\\tinyos\cygwin\bin\bash.exe --login -c \"$Command \"");
       	//echo ("C:\\tinyos\cygwin\bin\bash.exe --login -c \"$Command > /dev/null & echo $!\"");
	   }
	   return($PID);
   }
   /**
    * Check if the Application running !
    *
    * @param     unknown_type $PID
    * @return     boolen
    */
   function is_running($PID){
       exec("\"C:/Program Files/Programming/cygwin/bin/bash.exe\" --login -c \"ps $PID\"", $ProcessState);
       return(count($ProcessState) >= 2);
   }
   /**
    * Kill Application PID
    *
    * @param  unknown_type $PID
    * @return boolen
    */
   function kill($PID){
       if(exec::is_running($PID)){
           exec("\"C:/Program Files/Programming/cygwin/bin/bash.exe\" --login -c \"kill -KILL $PID\"");
           return true;
       }else return false;
   }
};
?>
