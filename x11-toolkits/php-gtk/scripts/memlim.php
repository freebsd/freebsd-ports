<?php
  /**
   * This script checks for the memory limit in php. If set too low
   * some .c-files cannot be created but contain a PHP error message.
   * 
   */

  $memlim= (int)ini_get ('memory_limit');
  if (!empty ($memlim) && $memlim < 10) {
    echo "--->  PHP not properly configured!\n";
    echo "     You do not have permitted enough memory for PHP. Please update\n";
    echo "     the memory_limit resource limit in your php.ini.\n\n";
    echo "     Recommended is 16M (or more) though 10M seem to work, too.\n";
    echo "     Current setting: ",$memlim,"\n\n";
    exit (0);
  }
  
  echo "--->  PHP: memory_limit is sufficient (",$memlim,")\n";
  exit(0);
  
?>
