--- daemon/getvt.c.orig	Tue Jan  6 14:56:39 2004
+++ daemon/getvt.c	Wed Jun 23 17:13:16 2004
@@ -19,15 +19,42 @@
 extern int GdmFirstVT;
 extern gboolean GdmVTAllocation;
 
-#ifdef __linux__
+#if defined (__linux__) || defined (__FreeBSD__)
 
+#ifdef __linux__
 #include <sys/vt.h>
+#endif
+#ifdef __FreeBSD__
+#include <sys/consio.h>
+#endif
+
+#ifdef __FreeBSD__
+static const char*
+__itovty(int val)
+{
+	static char str[8];
+	char* next = str + sizeof (str) - 1;
+
+	*next = '\0';
+	do {
+		*--next = "0123456789abcdefghigklmnopqrstuv"[val % 32];
+	} while (val /= 32);
+
+	return next;
+}
+#endif
 
 static int
 open_vt (int vtno)
 {
-	char *vtname = g_strdup_printf ("/dev/tty%d", vtno);
+	char *vtname;
 	int fd;
+
+#if defined (__linux__)
+	vtname = g_strdup_printf ("/dev/tty%d", vtno);
+#elif defined (__FreeBSD__)
+	vtname = g_strdup_printf ("/dev/ttyv%s", __itovty(vtno - 1));
+#endif
 	do {
 		errno = 0;
 		fd = open (vtname, O_RDWR
@@ -76,7 +103,11 @@
 		to_close_vts = g_list_prepend (to_close_vts,
 					       GINT_TO_POINTER (fdv));
 
+#if defined (__linux__)
 		if ((ioctl(fd, VT_OPENQRY, &vtno) < 0) || (vtno == -1)) {
+#elif defined (__FreeBSD__)
+		if (ioctl(fd, VT_OPENQRY, &vtno) == -1) {
+#endif
 			vtno = -1;
 			goto cleanup;
 		}
@@ -145,7 +176,11 @@
 int
 gdm_get_cur_vt (void)
 {
+#if defined (__linux__)
 	struct vt_stat s;
+#elif defined (__FreeBSD__)
+	int vtno;
+#endif
 	int fd;
 
 	do {
@@ -158,7 +193,7 @@
 	} while G_UNLIKELY (errno == EINTR);
 	if (fd < 0)
 		return -1;
-
+#if defined (__linux__)
 	ioctl (fd, VT_GETSTATE, &s);
 
 	VE_IGNORE_EINTR (close (fd));
@@ -167,6 +202,19 @@
 	printf ("current_Active %d\n", (int)s.v_active);
 
 	return s.v_active;
+#elif defined (__FreeBSD__)
+	if (ioctl (fd, VT_GETACTIVE, &vtno) == -1) {
+		VE_IGNORE_EINTR (close (fd));
+		return -1;
+	}
+
+	VE_IGNORE_EINTR (close (fd));
+
+	/* debug */
+	printf ("current_Active %d\n", vtno);
+
+	return vtno;
+#endif
 }
 
 #else /* here this is just a stub, we don't know how to do this outside
