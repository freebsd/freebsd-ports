--- mpeg2dec/libvo/video_out_x11.c.orig	Fri Jun  6 02:15:57 2003
+++ mpeg2dec/libvo/video_out_x11.c	Sun Jan 25 00:03:30 2004
@@ -235,7 +235,9 @@
     /* this would break the solaris port though :-/ */
 
     /* fuck solaris, plug the leak! */
+#ifndef __FreeBSD__
     shmctl(instance->shminfo.shmid, IPC_RMID, 0);
+#endif
 
     /* XShmAttach fails on remote displays, so we have to catch this event */
 
@@ -254,6 +256,9 @@
 	return NULL;
     }
 
+#ifdef __FreeBSD__
+    shmctl(instance->shminfo.shmid, IPC_RMID, 0);
+#endif
     return instance->shminfo.shmaddr;
 }
 
@@ -640,6 +645,9 @@
     if (instance == NULL)
 	return NULL;
 
+#ifdef __FreeBSD__
+    memset(instance, 0, sizeof(*instance));
+#endif
     instance->vo.setup = x11_setup;
     return (vo_instance_t *) instance;
 }
@@ -658,6 +666,9 @@
     if (instance == NULL)
 	return NULL;
 
+#ifdef __FreeBSD__
+    memset(instance, 0, sizeof(*instance));
+#endif
     instance->vo.setup = xv_setup;
     return (vo_instance_t *) instance;
 }
