--- programs/Xserver/hw/xfree86/input/mouse/mouse.c.orig	Wed Dec 19 08:05:22 2001
+++ programs/Xserver/hw/xfree86/input/mouse/mouse.c	Fri Aug  2 15:35:01 2002
@@ -1505,7 +1505,7 @@
 	    dy = - ((char)(pBuf[2]) + (char)(pBuf[4]));
 	    /* FreeBSD sysmouse sends additional data bytes */
 	    if (pMse->protoPara[4] >= 8) {
-		dz = ((char)(pBuf[5] << 1) + (char)(pBuf[6] << 1)) / 2;
+		dz = ((signed char)(pBuf[5] << 1) + (signed char)(pBuf[6] << 1)) >> 1;
 		buttons |= (int)(~pBuf[7] & 0x07) << 3;
 	    }
 	    break;
