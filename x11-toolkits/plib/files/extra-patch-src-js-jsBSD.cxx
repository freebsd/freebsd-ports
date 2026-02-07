--- src/js/jsBSD.cxx.orig	2008-03-11 05:06:21.000000000 +0300
+++ src/js/jsBSD.cxx	2009-09-04 19:20:14.000000000 +0400
@@ -66,6 +66,7 @@
 #  else
 #    define HAVE_USBHID_H 1
 #    include <usbhid.h>
+#    include <dev/usb/usb_ioctl.h>
 #  endif
 }
 #endif
@@ -116,54 +117,12 @@
 static char *
 walkusbdev(int f, char *dev, char *out, int outlen)
 {
-  struct usb_device_info di;
-  int i, a;
-  char *cp;
-
-  for (a = 1; a < USB_MAX_DEVICES; a++) {
-    di.udi_addr = a;
-    if (ioctl(f, USB_DEVICEINFO, &di) != 0)
-      return NULL;
-    for (i = 0; i < USB_MAX_DEVNAMES; i++)
-      if (di.udi_devnames[i][0] &&
-          strcmp(di.udi_devnames[i], dev) == 0) {
-        cp = new char[strlen(di.udi_vendor) + strlen(di.udi_product) + 2];
-        strcpy(cp, di.udi_vendor);
-        strcat(cp, " ");
-        strcat(cp, di.udi_product);
-        strncpy(out, cp, outlen - 1);
-	out[outlen - 1] = 0;
-	delete cp;
-        return out;
-      }
-  }
   return NULL;
 }
 
 static int
 findusbdev(char *name, char *out, int outlen)
 {
-  int i, f;
-  char buf[50];
-  char *cp;
-  static int protection_warned = 0;
-
-  for (i = 0; i < 16; i++) {
-    sprintf(buf, "%s%d", USBDEV, i);
-    f = open(buf, O_RDONLY);
-    if (f >= 0) {
-      cp = walkusbdev(f, name, out, outlen);
-      close(f);
-      if (cp)
-        return 1;
-    } else if (errno == EACCES) {
-      if (!protection_warned) {
-        fprintf(stderr, "Can't open %s for read!\n",
-          buf);
-        protection_warned = 1;
-      }
-    }
-  }
   return 0;
 }
 
