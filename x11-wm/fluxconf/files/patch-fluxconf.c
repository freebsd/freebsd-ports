--- fluxconf.c.orig	Tue Apr 30 12:28:32 2002
+++ fluxconf.c	Tue Apr 30 12:39:53 2002
@@ -160,8 +160,9 @@
 #define NB 16
 #define KEYLEN 30
 #define ACTLEN 30
-#define EXELEN 80
+#define EXELEN 255
 #define MAXKEYCOUNT 100
+#define MAXLINELEN 1024
 
 /* STRUCTURE ABOUT WIDGETS :
 
@@ -369,10 +370,10 @@
 		g_print("Can't open %s\n",initpath);
 		exit(1);
 	}
-	buf=(char*) malloc(100*sizeof(char));
+	buf=(char*) malloc(MAXLINELEN*sizeof(char)+1);
 	checkptr(buf);
 /* get all lines */
-	while(fgets(buf,100,file)) {
+	while(fgets(buf,MAXLINELEN,file)) {
 		config=realloc(config,1+i*sizeof(char*));
 		checkptr(config);
 		config[i-1]=(char*)malloc(15+strlen(buf)*sizeof(char)); /* I get some unused space for bigger numbers, etc...*/
@@ -535,8 +536,10 @@
 	gtk_button_set_relief(GTK_BUTTON(but),GTK_RELIEF_NONE);
 
 	gtk_widget_show_all(win);
+#ifndef WITHOUT_LOGO
 	gtk_timeout_add(100,(GtkFunction) show,logowin); /* show the logo */
 	gtk_timeout_add(3500,(GtkFunction) hide,logowin); /* hide the logo */
+#endif
 	gtk_main();
 	return 0;
 }
@@ -692,10 +695,10 @@
 		g_print("Can't open %s\n",initpath);
 		exit(1);
 	}
-	buf=(char*) malloc(KEYLEN+ACTLEN+EXELEN*sizeof(char));
+	buf=(char*) malloc(KEYLEN+ACTLEN+EXELEN*sizeof(char)+1);
 	checkptr(buf);
 	/* read the config */
-	while(fgets(buf,100,file)) {
+	while(fgets(buf,KEYLEN+ACTLEN+EXELEN,file)) {
 		config=realloc(config,1+i*sizeof(char*));
 		checkptr(config);
 		config[i-1]=(char*)malloc(10+strlen(buf)*sizeof(char)); 
@@ -770,8 +773,10 @@
     gtk_signal_connect(GTK_OBJECT(win), "destroy", GTK_SIGNAL_FUNC(gtk_main_quit), NULL);
 
 	gtk_widget_show_all(win);
+#ifndef WITHOUT_LOGO
 	gtk_timeout_add(100,(GtkFunction) show,logowin); /* show the logo */
 	gtk_timeout_add(3500,(GtkFunction) hide,logowin); /* hide the logo */
+#endif
 	gtk_main();
 
 
