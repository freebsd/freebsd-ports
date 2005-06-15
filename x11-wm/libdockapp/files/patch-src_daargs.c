--- src/daargs.c.orig	Thu Apr 21 04:05:04 2005
+++ src/daargs.c	Wed Jun 15 21:32:35 2005
@@ -85,8 +85,11 @@
 	for (j = 0; j < count; j++) {
 	    DAProgramOption *option = &options[j];
 
+	    /* A number of ports depend on the old libdockapp behaviour
+	     * which permitted short form options longer than one character
+	     */
 	    if ((option->longForm && strcmp(option->longForm, optStr) == 0) ||
-		(option->shortForm && contains(option->shortForm, optStr)))
+		(option->shortForm && strcmp(option->shortForm, optStr) == 0))
 	    {
 		found = 1;
 		i = parseOption(option, i, argc, argv);
