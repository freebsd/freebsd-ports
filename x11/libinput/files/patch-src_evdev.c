When a process without full /dev/input access enumerates devices via libudev-devd,
the udev_device structs do not get udev properties that mark them as inputs, keyboards, etc,
and get rejected as not being input devices.

libinput reopens devices just to check path equality.
The udev_devices from reopening do have the right properties,
so we just use them instead of the original (enumerated) ones.

--- src/evdev.c.orig	2026-04-02 01:04:12 UTC
+++ src/evdev.c
@@ -1007,7 +1007,7 @@ evdev_sync_device(struct libinput *libinput, struct ev
 
 	evdev_device_dispatch_frame(libinput, device, frame);
 
-	return rc == -EAGAIN ? 0 : rc;
+	return (rc == -EAGAIN || rc == -EINVAL)? 0 : rc;
 }
 
 static inline void
@@ -1105,6 +1105,17 @@ evdev_device_dispatch(void *data)
 
 	if (rc != -EAGAIN && rc != -EINTR) {
 		libinput_remove_source(libinput, device->source);
+		/*
+		 * Dirty hack to allow cuse-based evdev backends to release
+		 * character device file when device has been detached
+		 * but still have it descriptor opened.
+		 * Issuing evdev_device_suspend() here leads to SIGSEGV
+		 */
+		int dummy_fd = open("/dev/null", O_RDONLY | O_CLOEXEC);
+		if (dummy_fd >= 0) {
+			dup2(dummy_fd, device->fd);
+			close(dummy_fd);
+		}
 		device->source = NULL;
 	}
 }
