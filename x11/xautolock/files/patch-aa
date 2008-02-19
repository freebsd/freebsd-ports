--- src/engine.c.orig	2007-12-28 15:15:26.000000000 -0200
+++ src/engine.c	2008-02-18 23:25:01.000000000 -0300
@@ -210,7 +210,9 @@
 #else /* VMS */
   if (lockerPid)
   {
-#if !defined (UTEKV) && !defined (SYSV) && !defined (SVR4)
+#if defined (__FreeBSD__)
+    int		status;
+#elif !defined (UTEKV) && !defined (SYSV) && !defined (SVR4)
     union wait  status;      /* childs process status */
 #else /* !UTEKV && !SYSV && !SVR4 */
     int         status = 0;  /* childs process status */
@@ -283,7 +285,7 @@
     *  For the time being, VMS users are out of luck: their xautolock
     *  will indeed block until the killer returns.
     */
-    { int dummy; dummy = system (killer); } // Silly gcc...
+    { int dummy; dummy = system (killer); } /* Silly gcc... */
     setKillTrigger (killTime);
   }
 
@@ -299,7 +301,7 @@
      /*
       *  Here we use the same dirty trick as for the killer command.
       */
-      { int dummy; dummy = system (notifier); } // Silly gcc...
+      { int dummy; dummy = system (notifier); } /* Silly gcc... */
     }
     else
     {
