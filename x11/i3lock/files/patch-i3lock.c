--- ./i3lock.c.orig	2013-03-19 21:44:37.876383724 +0100
+++ ./i3lock.c	2013-03-20 19:23:55.060606716 +0100
@@ -525,6 +525,8 @@
                     /* In the parent process, we exit */
                     if (fork() != 0)
                         exit(0);
+
+                    ev_loop_fork(EV_DEFAULT);
                 }
                 break;
 
@@ -645,11 +647,16 @@
     if (ret != PAM_SUCCESS)
         errx(EXIT_FAILURE, "PAM: %s", pam_strerror(pam_handle, ret));
 
+/* Using mlock() as non-super-user seems only possible in Linux. Users of other
+ * operating systems should use encrypted swap/no swap (or remove the ifdef and
+ * run i3lock as super-user). */
+#if defined(__linux__)
     /* Lock the area where we store the password in memory, we don’t want it to
      * be swapped to disk. Since Linux 2.6.9, this does not require any
      * privileges, just enough bytes in the RLIMIT_MEMLOCK limit. */
     if (mlock(password, sizeof(password)) != 0)
         err(EXIT_FAILURE, "Could not lock page in memory, check RLIMIT_MEMLOCK");
+#endif
 
     /* Initialize connection to X11 */
     if ((conn = xcb_connect(NULL, &nscreen)) == NULL ||
@@ -731,9 +738,11 @@
     ev_check_init(xcb_check, xcb_check_cb);
     ev_check_start(main_loop, xcb_check);
 
+    ev_check_init(xcb_check, xcb_check_cb);
     ev_prepare_init(xcb_prepare, xcb_prepare_cb);
     ev_prepare_start(main_loop, xcb_prepare);
 
+    ev_check_init(xcb_check, xcb_check_cb);
     /* Invoke the event callback once to catch all the events which were
      * received up until now. ev will only pick up new events (when the X11
      * file descriptor becomes readable). */
