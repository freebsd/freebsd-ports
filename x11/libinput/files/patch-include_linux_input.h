--- include/linux/input.h.orig	2016-12-05 05:15:21 UTC
+++ include/linux/input.h
@@ -11,7 +11,17 @@
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <sys/types.h>
+#ifdef __FreeBSD__
+#define __u8 uint8_t
+#define __u16 uint16_t
+#define __u32 uint32_t
+#define __s16 int16_t
+#define __s32 int32_t
+#define _IOC_READ IOC_OUT
+#define _IOC_WRITE IOC_IN
+#else
 #include <linux/types.h>
+#endif
 
 /*
  * The event structure itself
@@ -132,7 +142,7 @@ struct input_keymap_entry {
  *
  * If the request code is not an ABS_MT value, -EINVAL is returned.
  */
-#define EVIOCGMTSLOTS(len)	_IOC(_IOC_READ, 'E', 0x0a, len)
+#define EVIOCGMTSLOTS(len)	_IOC(IOC_INOUT, 'E', 0x0a, len)
 
 #define EVIOCGKEY(len)		_IOC(_IOC_READ, 'E', 0x18, len)		/* get global key state */
 #define EVIOCGLED(len)		_IOC(_IOC_READ, 'E', 0x19, len)		/* get all LEDs */
@@ -147,7 +157,7 @@ struct input_keymap_entry {
 #define EVIOCRMFF		_IOW('E', 0x81, int)			/* Erase a force effect */
 #define EVIOCGEFFECTS		_IOR('E', 0x84, int)			/* Report number of effects playable at the same time */
 
-#define EVIOCGRAB		_IOW('E', 0x90, int)			/* Grab/Release device */
+#define EVIOCGRAB		_IO('E', 0x90)				/* Grab/Release device */
 #define EVIOCREVOKE		_IOW('E', 0x91, int)			/* Revoke device access */
 
 #define EVIOCSCLOCKID		_IOW('E', 0xa0, int)			/* Set clockid to be used for timestamps */
