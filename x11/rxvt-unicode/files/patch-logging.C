--- src/logging.C.orig	Wed Jan 19 16:16:06 2005
+++ src/logging.C	Thu Feb  3 22:42:35 2005
@@ -73,17 +73,17 @@
   if (!strncmp (pty, "/dev/", 5))
     pty += 5;		/* skip /dev/ prefix */
 
+#ifdef HAVE_UTMP_PID
   if (!strncmp (pty, "pty", 3) || !strncmp (pty, "tty", 3))
     strncpy (ut_id, (pty + 3), sizeof (ut_id));
-#ifdef HAVE_UTMP_PID
   else if (sscanf (pty, "pts/%d", &i) == 1)
     sprintf (ut_id, "vt%02x", (i & 0xff));	/* sysv naming */
-#endif
   else if (strncmp (pty, "pty", 3) && strncmp (pty, "tty", 3))
     {
       rxvt_warn ("can't parse tty name \"%s\", not adding utmp entry.\n", pty);
       return;
     }
+#endif
 
 #ifdef HAVE_STRUCT_UTMP
   memset (ut, 0, sizeof (struct utmp));
