--- scripts/setup.sh.orig	Wed Jun 22 16:33:18 2005
+++ scripts/setup.sh	Wed Jun 22 19:18:06 2005
@@ -4,16 +4,15 @@
 if [ ${RESULT} -eq 0 ]; then
 	kldunload -n nvidia > /dev/null 2>&1; RESULT=$?
 	if [ ${RESULT} -ne 0 ]; then
-		echo 'ERROR: Failed to unload the NVIDIA module!'
-		echo 'ERROR: Is nvidia.ko in use?'
-		exit 1;
+		echo 'NOTICE: Failed to unload the NVIDIA module!'
+		echo 'NOTICE: Is nvidia.ko in use?'
 	fi
 fi
 
 kldload nvidia > /dev/null 2>&1 ; RESULT=$?
 if [ ${RESULT} -ne 0 ]; then
-	echo 'ERROR: Failed to load the NVIDIA module!'
-	exit 1;
+	echo 'NOTICE: Failed to load the NVIDIA module!'
+	echo 'NOTICE: Unload and load NVIDIA module manually, or reboot.'
 fi
 
 grep nvidia_load /boot/loader.conf > /dev/null 2>&1; RESULT=$?
