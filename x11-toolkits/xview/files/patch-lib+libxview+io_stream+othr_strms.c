--- ./lib/libxview/io_stream/othr_strms.c.orig	Tue Jun 29 07:15:05 1993
+++ ./lib/libxview/io_stream/othr_strms.c	Sat Apr  1 18:25:24 2000
@@ -17,7 +17,11 @@ static char     sccsid[] = "@(#)othr_str
 
 #define GetFCSData struct xv_filter_comments_stream_data *data = (struct xv_filter_comments_stream_data*) in->client_data
 
+#ifndef __FreeBSD__
 static struct xv_filter_comments_stream_data {
+#else
+struct xv_filter_comments_stream_data {
+#endif
     Bool            backed_up;
     char            backup, lastchar;
 };
