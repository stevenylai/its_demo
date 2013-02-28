<?php
set_time_limit(0);

//$result = shell_exec("C:\cygwin\bin\bash.exe --login -c '/cygdrive/c/cygwin/bin/conv.exe --version'");
//$result = shell_exec("C:\cygwin\bin\bash.exe --login -c 'cd /opt/tinyos-2.x/apps/Blink/; make micaz reinstall.0 mib520./dev/ttyS0'");
//$result = shell_exec("C:\cygwin\bin\bash.exe --login -c 'pwd");
//print( $result);

$result = shell_exec("C:\cygwin\bin\bash.exe --login -c 'cd /home/garytsoi; java GoodWindowsExec \"cd /opt/tinyos-2.x/apps/Blink/;make micaz\"'");

print( $result);

//$result = shell_exec("C:\cygwin\bin\bash.exe --login -c 'pwd");
//print( $result);
/*$last_line = system("C:\cygwin\bin\bash.exe --login 'cd /opt/tinyos-2.x/apps/Blink/;make micaz reinstall.0 mib520./dev/ttyS0''", $retval);
echo '<hr />Last line of the output: ' . $last_line . '<hr />Return value: ' . $retval;
*/


/*
print "Hello from PHP! 2";
$perl = new Perl();
$perl->require("test1.pl");
print "Bye! ";
*/
?>
