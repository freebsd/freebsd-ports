--- ./lib/libxview/io_stream/file_strms.c.orig	Tue Jun 29 07:15:07 1993
+++ ./lib/libxview/io_stream/file_strms.c	Sat Apr  1 18:25:24 2000
@@ -17,7 +17,11 @@ static char     sccsid[] = "@(#)file_str
 
 #define GetFISData struct xv_file_input_stream_data *data = (struct xv_file_input_stream_data*) in->client_data
 
+#ifndef __FreeBSD__
 static struct xv_file_input_stream_data {
+#else
+struct xv_file_input_stream_data {
+#endif
     FILE           *fp;
     int             lineno;
 };
@@ -156,7 +160,11 @@ xv_file_input_stream(s, fp)
 
 #define GetFOSData struct xv_file_output_stream_data *data = (struct xv_file_output_stream_data*) out->client_data
 
+#ifndef __FreeBSD__
 static struct xv_file_output_stream_data {
+#else
+struct xv_file_output_stream_data {
+#endif
     FILE           *fp;
     int             lineno;
 };
