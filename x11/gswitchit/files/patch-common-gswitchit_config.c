--- common/gswitchit_config.c.orig	Mon Jun  9 09:02:24 2003
+++ common/gswitchit_config.c	Mon Jun  9 09:03:28 2003
@@ -660,7 +660,7 @@
     for( i = data.numOptions; --i >= 0; )
     {
       char group[XKL_MAX_CI_NAME_LENGTH];
-      char *delim = strchr( *p, ':' );
+      char *delim = *p ? strchr( *p, ':' ) : NULL;
       int len;
       if( ( delim != NULL ) &&
           ( ( len = ( delim - *p ) ) < XKL_MAX_CI_NAME_LENGTH ) )
