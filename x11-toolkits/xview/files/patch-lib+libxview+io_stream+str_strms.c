--- ./lib/libxview/io_stream/str_strms.c.orig	Tue Jun 29 07:15:06 1993
+++ ./lib/libxview/io_stream/str_strms.c	Sat Apr  1 18:25:24 2000
@@ -17,7 +17,11 @@ static char     sccsid[] = "@(#)str_strm
 
 #define GetSISData struct string_input_stream_data	*data = (struct string_input_stream_data*) in->client_data
 
+#ifndef __FreeBSD__
 static struct string_input_stream_data {
+#else
+struct string_input_stream_data {
+#endif
     char           *string;
     int             charpos;
 };
@@ -148,7 +152,11 @@ string_input_stream(s, in)
 
 #define GetSOSData struct string_output_stream_data *data = (struct string_output_stream_data*) out->client_data
 
+#ifndef __FreeBSD__
 static struct string_output_stream_data {
+#else
+struct string_output_stream_data {
+#endif
     char           *string;
     int             charpos;
 };
