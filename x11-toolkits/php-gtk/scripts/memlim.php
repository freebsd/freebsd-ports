<?php
  /**
   * This script checks for the memory limit in php. If set too low
   * some .c-files cannot be created but contain a PHP error message.
   * 
   */

  if (((int)ini_get ('memory_limit')) < 10) {
    echo "--->  PHP not properly configured!\n";
    echo "     You do not have permitted enough memory for PHP. Please update\n";
    echo "     the memory_limit resource limit in your php.ini.\n\n";
    echo "     Recommended is 16M (or more) though 10M seem to work, too.\n";
    echo "     Current setting: ",ini_get('memory_limit'),"\n\n";
    exit (-1);
  }
  
  echo "--->  PHP: memory_limit is sufficient (",ini_get ('memory_limit'),")\n";
  exit(0);
  
?>
