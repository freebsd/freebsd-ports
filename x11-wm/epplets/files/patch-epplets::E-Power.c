--- epplets/E-Power.c.orig	Sun Oct 14 03:32:19 2001
+++ epplets/E-Power.c	Mon Dec  8 03:32:37 2003
@@ -1,5 +1,12 @@
 #include "epplet.h"
 
+#ifdef __FreeBSD__
+#include <stdio.h>
+#include <fcntl.h>
+#include <sys/ioctl.h>
+#include <machine/apm_bios.h>
+#endif
+
 int                prev_bat_val = 110;
 int                bat_val = 0;
 int                time_val = 0;
@@ -18,16 +25,34 @@
 static void
 cb_timer(void *data)
 {
+#ifdef __FreeBSD__
+   int fd;
+
+   fd = open("/dev/apm", O_RDONLY);
+   if (fd != -1)
+#else
    static FILE *f;
 
    f = fopen("/proc/apm", "r");
    if (f)
+#endif
      {
 	char s[256], s1[32], s2[32], s3[32];
 	int apm_flags, ac_stat, bat_stat, bat_flags;
 	int  i, hours, minutes, up, up2;
 	char *s_ptr;
 	
+#ifdef __FreeBSD__
+	struct apm_info info;
+       
+	ioctl(fd,APMIO_GETINFO,&info);
+	ac_stat=info.ai_acline;
+	bat_stat=info.ai_batt_stat;
+	time_val=info.ai_batt_time;
+	bat_val=info.ai_batt_life;
+
+	close(fd);
+#else
 	fgets(s, 255, f);
 	sscanf(s, "%*s %*s %x %x %x %x %s %s %s", &apm_flags, &ac_stat, &bat_stat, &bat_flags, s1, s2, s3);
 	s1[strlen(s1) - 1] = 0;
@@ -37,6 +62,7 @@
 	else if (!strcmp(s3, "min"))
 	   time_val = atoi(s2) * 60;
 	fclose(f);
+#endif
 	
 	up = bat_val - prev_bat_val;
 	up2 = up;
@@ -52,6 +78,7 @@
 	
         s_ptr = s;
 
+#ifndef __FreeBSD__
         if( bat_flags != 0xff
 	    && bat_flags & 0x80 )
 	  {
@@ -59,6 +86,7 @@
 	  }
 	else
 	  {
+#endif
 	    if( bat_val > 0 )
 	      s_ptr += sprintf( s_ptr, "%i%%", bat_val );
 
@@ -77,7 +105,9 @@
 	          s_ptr += sprintf( s_ptr, ", charge" );
 		  break;
 	      }
+#ifndef __FreeBSD__
 	  }
+#endif
 	s_ptr += sprintf( s_ptr, "\n" );
 
 
@@ -87,6 +117,9 @@
           }
         else
           {
+#ifdef __FreeBSD__
+	    if( time_val >= 0){
+#endif
 	    hours = time_val / 3600;
             minutes = (time_val / 60) % 60;
 	    if (up2 > 0)
@@ -96,6 +129,11 @@
 		       		hours, minutes);
 	    else
 	       s_ptr += sprintf(s_ptr, "%i:%02i", hours, minutes);
+#ifdef __FreeBSD__
+	    }
+	    else
+	       s_ptr += sprintf(s_ptr, "unknown");
+#endif
           }
 	Epplet_change_label(label, s);
 
