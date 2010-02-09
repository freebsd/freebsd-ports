--- kdm/backend/sessreg.c
+++ kdm/backend/sessreg.c
@@ -43,6 +43,13 @@
 # define NO_LASTLOG
 #endif
 
+#ifdef __FreeBSD__
+# include <sys/param.h>
+# if __FreeBSD_version >= 900007
+#  define NO_LASTLOG
+# endif
+#endif
+
 #ifndef NO_LASTLOG
 # ifdef HAVE_LASTLOG_H
 #  include <lastlog.h>
@@ -254,7 +261,6 @@
 		close( utmp );
 	}
 # else
-	UTMPNAME( UTMP_FILE );
 	SETUTENT();
 	PUTUTLINE( &ut_ent );
 	ENDUTENT();
