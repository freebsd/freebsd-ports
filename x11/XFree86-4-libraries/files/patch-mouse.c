--- programs/Xserver/hw/xfree86/input/mouse/mouse.c.orig	Wed Dec 19 16:05:22 2001
+++ programs/Xserver/hw/xfree86/input/mouse/mouse.c	Thu Jan  9 22:48:18 2003
@@ -1505,8 +1505,8 @@
 	    dy = - ((char)(pBuf[2]) + (char)(pBuf[4]));
 	    /* FreeBSD sysmouse sends additional data bytes */
 	    if (pMse->protoPara[4] >= 8) {
-		dz = ((char)(pBuf[5] << 1) + (char)(pBuf[6] << 1)) / 2;
-		buttons |= (int)(~pBuf[7] & 0x07) << 3;
+		dz = ((signed char)(pBuf[5] << 1) + (signed char)(pBuf[6] << 1)) >> 1;
+		buttons |= (int)(~pBuf[7] & 0x7f) << 3;
 	    }
 	    break;
 
