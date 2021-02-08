--- main.c.orig	2021-02-02 00:20:59 UTC
+++ main.c
@@ -2210,9 +2210,6 @@ main(int argc, char *argv[]ENVP_ARG)
     char *my_class = x_strdup(DEFCLASS);
     unsigned line_speed = VAL_LINE_SPEED;
     Window winToEmbedInto = None;
-#if defined(HAVE_LIB_XAW3DXFT)
-    Xaw3dXftData *xaw3dxft_data;
-#endif
 
     ProgramName = argv[0];
 
@@ -2330,12 +2327,6 @@ main(int argc, char *argv[]ENVP_ARG)
     /* This dumped core on HP-UX 9.05 with X11R5 */
 #if OPT_I18N_SUPPORT
     XtSetLanguageProc(NULL, NULL, NULL);
-#endif
-
-    /* enable Xft support in Xaw3DXft */
-#if defined(HAVE_LIB_XAW3DXFT)
-    GET_XAW3DXFT_DATA(xaw3dxft_data);
-    xaw3dxft_data->encoding = -1;
 #endif
 
 #ifdef TERMIO_STRUCT		/* { */
