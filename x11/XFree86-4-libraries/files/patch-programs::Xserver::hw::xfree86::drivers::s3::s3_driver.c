
$FreeBSD$

--- programs/Xserver/hw/xfree86/drivers/s3/s3_driver.c	2002/08/26 06:45:40	1.1
+++ programs/Xserver/hw/xfree86/drivers/s3/s3_driver.c	2002/08/26 06:49:53
@@ -174,6 +174,7 @@
 #ifdef S3_USEFB
 static const char *fbSymbols[] = {
         "fbScreenInit",
+	"fbPictureInit",
         NULL
 };
 #else
@@ -850,6 +851,11 @@
                         }
                 } 
         }
+
+#ifdef S3_USEFB
+	/* must be after RGB order fixed */
+	fbPictureInit (pScreen, 0, 0);
+#endif
 
 	S3DGAInit(pScreen);
 
