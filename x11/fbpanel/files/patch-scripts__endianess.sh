--- ./scripts/endianess.sh.orig	2009-06-01 07:55:28.000000000 -0700
+++ ./scripts/endianess.sh	2010-11-17 11:06:07.000000000 -0800
@@ -1,16 +1,13 @@
-#!/bin/bash
+#!/bin/sh
 
 # When cross compiling, you may put cross compiler directory 
 # in PATH before native gcc (aka spoofing), or you may set CC 
 # to exact name of cross compiler:
 #    CC=/opt/ppc_gcc/bin/gcc endianess
 
-# x86 and friends are considerd LITTLE endian, all others are BIG
-a=`${CC:-gcc} -v 2>&1 | grep Target`
-[ $? -ne 0 ] && exit 1
-#echo $a
+a=`sysctl -n hw.byteorder`
 
-if [ "${a/86/}" != "$a" ]; then
+if [ "${a}" == "1234" ]; then	
     echo LITTLE
 else
     echo BIG
