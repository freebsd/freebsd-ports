--- extconf.rb.orig	Sun Dec 24 18:55:56 2000
+++ extconf.rb	Wed Jan 10 05:18:54 2001
@@ -14,20 +14,15 @@
 # --with-qt2-dir=/usr/lib/qt-2
 dir_config('qt2')
 
-# e.g. --with-qti18n if you use i18n patched Qt lib.
-qti18n = with_config('qti18n')
+dir_config('x11')
 
-if qti18n
-  $CFLAGS += ' -DI18NQT'
-end
-
-qt = if qti18n.kind_of?(String) then qti18n else 'qt' end
+qt2 = with_config('qt2', 'qt')
 
 $CFLAGS += ' -I. -O -w ' 
 
 p $CFLAGS
 
-if have_header('qapplication.h') and have_library(qt)
+if have_header('qapplication.h') and have_library(qt2)
   create_makefile('qt2')
 else
   print "You do not seem to have qt library. Plrease check qt or extconf.rb.\n"
