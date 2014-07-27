--- ./gadgets/kittscanner.sh.orig	2014-06-17 15:00:13.000000000 +0200
+++ ./gadgets/kittscanner.sh	2014-06-17 15:00:24.000000000 +0200
@@ -19,10 +19,10 @@
 
 SLEEP=0.1
 
-#DZEN=/usr/local/bin/dzen2
-DZEN=../dzen2
-#DZENOPTS="-bg $BG -fg $INACTIVE_LED_COLOR"
-DZENOPTS="-bg $BG -fg $INACTIVE_LED_COLOR -xs 1 -y 30"
+DZEN=/usr/local/bin/dzen2
+#DZEN=../dzen2
+DZENOPTS="-bg $BG -fg $INACTIVE_LED_COLOR"
+#DZENOPTS="-bg $BG -fg $INACTIVE_LED_COLOR -xs 1 -y 30"
 
 #-----------------------------------------------------------------------
 
