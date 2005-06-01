--- lib/libxview/base/xv_parse.c~	2005-01-15 17:11:54.000000000 +0100
+++ lib/libxview/base/xv_parse.c	2005-01-15 17:20:23.000000000 +0100
@@ -312,7 +312,7 @@ xv_parse_one(app_name, argc, argv)
     if (argc <= slot->num_args) {
 	char            dummy[128];
 
-	(void) sprintf(dummy, 
+	(void) snprintf(dummy, sizeof(dummy),
 			XV_MSG("%s: missing argument after %s"), 
 			app_name,
 		       argv[0]);
@@ -392,7 +392,7 @@ xv_parse_one(app_name, argc, argv)
 	if (defaults_lookup(argv[1], known_scales) == -1) {
 		char dummy[1024];
 		
-		(void) sprintf(dummy, 
+		(void) snprintf(dummy, sizeof(dummy),
 			XV_MSG("%s: unknown scale \"%s\" used with %s option"),
 			       app_name, argv[1], argv[0]);
 		xv_error(XV_NULL,
@@ -611,7 +611,7 @@ NegArg:
     {
 	char            dummy[128];
 
-	(void) sprintf(dummy, 
+	(void) snprintf(dummy, sizeof(dummy),
 		XV_MSG("%s: can't have negative argument %s after %s"),
 		       app_name, argv[bad_arg], argv[0]);
 	xv_error(XV_NULL,
