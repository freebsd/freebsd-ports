--- src/functions.c.orig	Wed Aug 23 20:55:58 2006
+++ src/functions.c	Thu Feb  1 11:04:42 2007
@@ -45,7 +45,9 @@
 				tmp->time = new_tmp->time;
 				
 				
+#ifndef __FreeBSD__
 				tmp->time_percentage = (gdouble)(tmp->time - tmp->old_time) * (gdouble)(1000.0 / REFRESH_INTERVAL);
+#endif
 				
 				if((gint)tmp->ppid != (gint)new_tmp->ppid || strcmp(tmp->state,new_tmp->state) || (unsigned int)tmp->size != (unsigned int)new_tmp->size || (unsigned int)tmp->rss != (unsigned int)new_tmp->rss || (unsigned int)tmp->time != (unsigned int)tmp->old_time)
 				{
