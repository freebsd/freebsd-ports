--- extconf.rb.orig	Thu Mar  1 15:41:16 2001
+++ extconf.rb	Thu Mar 15 03:08:48 2001
@@ -14,12 +14,12 @@
 # --with-qt2-dir=/usr/lib/qt-2
 dir_config('qt2')
 
-
+qt2 = with_config('qt2','qt')
 
 #qt = if qti18n.kind_of?(String) then qti18n else 'qt' end
 $CFLAGS += ' -I. -O ' 
 
-if have_library('qt') and have_header('qiconview.h') 
+if have_library(qt2) and have_header('qiconview.h') 
   create_makefile('qt2iconview')
 else
   print "You do not seem to have qt(+qtable) library. Plrease check qt or extconf.rb.\n"
