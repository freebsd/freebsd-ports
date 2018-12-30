When a process without full /dev/input access enumerates devices via libudev-devd,
the udev_device structs do not get udev properties that mark them as inputs, keyboards, etc,
and get rejected as not being input devices.

libinput reopens devices just to check path equality.
The udev_devices from reopening do have the right properties,
so we just use them instead of the original (enumerated) ones.

--- src/evdev.c.orig	2018-06-09 12:13:43 UTC
+++ src/evdev.c
@@ -895,7 +895,7 @@ evdev_sync_device(struct evdev_device *device)
 		evdev_device_dispatch_one(device, &ev);
 	} while (rc == LIBEVDEV_READ_STATUS_SYNC);
 
-	return rc == -EAGAIN ? 0 : rc;
+	return (rc == -EAGAIN || rc == -EINVAL)? 0 : rc;
 }
 
 static void
@@ -933,6 +933,17 @@ evdev_device_dispatch(void *data)
 
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
@@ -1785,9 +1796,9 @@ evdev_notify_added_device(struct evdev_device *device)
 }
 
 static bool
-evdev_device_have_same_syspath(struct udev_device *udev_device, int fd)
+evdev_device_have_same_syspath(struct udev_device **udev_device, int fd, bool reopen)
 {
-	struct udev *udev = udev_device_get_udev(udev_device);
+	struct udev *udev = udev_device_get_udev(*udev_device);
 	struct udev_device *udev_device_new = NULL;
 	struct stat st;
 	bool rc = false;
@@ -1800,10 +1811,16 @@ evdev_device_have_same_syspath(struct udev_device *ude
 		goto out;
 
 	rc = streq(udev_device_get_syspath(udev_device_new),
-		   udev_device_get_syspath(udev_device));
+		   udev_device_get_syspath(*udev_device));
 out:
-	if (udev_device_new)
-		udev_device_unref(udev_device_new);
+	if (udev_device_new) {
+		if (reopen) {
+			udev_device_unref(*udev_device);
+			*udev_device = udev_device_new;
+		} else {
+			udev_device_unref(udev_device_new);
+		}
+	}
 	return rc;
 }
 
@@ -2003,7 +2020,7 @@ evdev_device_create(struct libinput_seat *seat,
 		return NULL;
 	}
 
-	if (!evdev_device_have_same_syspath(udev_device, fd))
+	if (!evdev_device_have_same_syspath(&udev_device, fd, true))
 		goto err;
 
 	device = zalloc(sizeof *device);
@@ -2559,7 +2576,7 @@ evdev_device_resume(struct evdev_device *device)
 	if (fd < 0)
 		return -errno;
 
-	if (!evdev_device_have_same_syspath(device->udev_device, fd)) {
+	if (!evdev_device_have_same_syspath(&device->udev_device, fd, false)) {
 		close_restricted(libinput, fd);
 		return -ENODEV;
 	}
