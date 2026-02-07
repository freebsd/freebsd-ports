--- src/random.c.orig	2004-12-09 17:01:43 UTC
+++ src/random.c
@@ -13,7 +13,7 @@ int syserr;
 
 #define ALLOC_STEP 1000
 regex_t regexp;
-int size_files=0, used_files=0, i=0;
+int size_files=0, used_files=0;
 char **files, *wyjscie;
 regmatch_t matchpos;
 
@@ -70,9 +70,9 @@ return;
 
 char *randomly_select_font(const char *wejscie){
 
-files=NULL;wyjscie=NULL;size_files=0;used_files=0;i=0;
+files=NULL;wyjscie=NULL;size_files=0;used_files=0;;
 
-regcomp(&regexp,"^.*\\.ttf$",REG_ICASE||REG_NOSUB);
+regcomp(&regexp,"^.*\\.ttf$",REG_ICASE|REG_NOSUB);
 
 add_file(wejscie);
 
@@ -80,7 +80,7 @@ if (used_files==0) {
 	return NULL;
 }
 
-i=rand()%used_files;
+int i=rand()%used_files;
 wyjscie=malloc(strlen(files[i])+1);
 strcpy(wyjscie,files[i]);
 
@@ -92,9 +92,9 @@ return wyjscie;
 
 char *randomly_select_image(const char *wejscie){
 
-files=NULL;wyjscie=NULL;size_files=0;used_files=0;i=0;
+files=NULL;wyjscie=NULL;size_files=0;used_files=0;;
 
-regcomp(&regexp,"^.*\\.(bmp|jpg|jpeg|png|tiff|tif|tga|gif|pcx|xpm|pnm|ppm|xbm)$",REG_ICASE||REG_NOSUB);
+regcomp(&regexp,"^.*\\.(bmp|jpg|jpeg|png|tiff|tif|tga|gif|pcx|xpm|pnm|ppm|xbm)$",REG_ICASE|REG_NOSUB);
 
 add_file(wejscie);
 
@@ -102,7 +102,7 @@ if (used_files==0) {
 	return NULL;
 }
 
-i=rand()%used_files;
+int i=rand()%used_files;
 wyjscie=malloc(strlen(files[i])+1);
 strcpy(wyjscie,files[i]);
 
