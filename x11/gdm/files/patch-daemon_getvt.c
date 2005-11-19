--- daemon/getvt.c.orig	Mon Nov 14 22:20:51 2005
+++ daemon/getvt.c	Mon Nov 14 22:40:39 2005
@@ -87,8 +87,10 @@ get_free_vt (int *vtfd)
 {
 	int fd, fdv;
 	int vtno;
+#if defined(__linux__)
 	unsigned short vtmask;
 	struct vt_stat vtstat;
+#endif
 
 	*vtfd = -1;
 
@@ -103,23 +105,50 @@ get_free_vt (int *vtfd)
 	if (fd < 0)
 		return -1;
 
+#if defined(__linux__)
 	if (ioctl (fd, VT_GETSTATE, &vtstat) < 0) {
+#elif defined (__FreeBSD__) || defined(__DragonFly__)
+	if ((ioctl(fd, VT_OPENQRY, &vtno) < 0) || (vtno == -1)) {
+#endif
 		VE_IGNORE_EINTR (close (fd));
 		return -1;
 	}
 
+#if defined(__linux__)
 	for (vtno = GdmFirstVT, vtmask = 1 << (vtno-1);
 			vtstat.v_state & vtmask; vtno++, vtmask <<= 1);
 	if (!vtmask) {
+#elif defined (__FreeBSD__) || defined(__DragonFly__)
+	fdv = open_vt(vtno);
+	if (fdv < 0) {
+#endif
 		VE_IGNORE_EINTR (close (fd));
 		return -1;
 	}
 
+#if defined(__linux__)
 	fdv = open_vt (vtno);
 	if (fdv < 0) {
 		VE_IGNORE_EINTR (close (fd));
 		return -1;
 	}
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+	while (vtno < GdmFirstVT) {
+		if (fdv > -1)
+			VE_IGNORE_EINTR (close (fdv));
+
+		if (ioctl(fd, VT_OPENQRY, &vtno) == -1) {
+			VE_IGNORE_EINTR (close (fd));
+			return -1;
+		}
+
+		fdv = open_vt (vtno);
+		if (fdv < 0) {
+			VE_IGNORE_EINTR (close (fd));
+			return -1;
+		}
+	}
+#endif
 	*vtfd = fdv;
 	return vtno;
 }
