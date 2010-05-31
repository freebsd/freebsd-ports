--- epplets/E-Slides.c.orig	2008-03-10 17:24:51.000000000 +0100
+++ epplets/E-Slides.c	2008-03-10 17:26:19.000000000 +0100
@@ -53,18 +53,18 @@
 #define AUTOBG_SCALED   2
 #define AUTOBG_PSCALED  3
 
-Epplet_gadget       close_button, play_button, pause_button, prev_button,
-   next_button, cfg_button, cfg_popup, picture;
-Epplet_gadget       cfg_tb_path, cfg_tb_delay, cfg_tb_zoom;
-unsigned long       idx = 0, image_cnt = 0;
-double              delay = 5.0;
-char              **filenames = NULL, *path, *zoom_cmd;
-unsigned char       paused = 0, randomize = 0, auto_setbg =
-   AUTOBG_OFF, maintain_aspect = 0;
-int                 cfg_auto_setbg = AUTOBG_OFF, cfg_maintain_aspect =
-   0, cfg_randomize = 0;
-Window              zoom_win = None, config_win = None;
-int                 w = 3, h = 3;
+Epplet_gadget        close_button, play_button, pause_button, prev_button,
+                     next_button, cfg_button, cfg_popup, picture;
+Epplet_gadget        cfg_tb_path, cfg_tb_delay, cfg_tb_zoom;
+unsigned long        idx = 0, image_cnt = 0;
+double               delay = 5.0;
+char               **filenames = NULL, *path, *zoom_cmd;
+unsigned char        paused = 0, randomize = 0, auto_setbg = AUTOBG_OFF,
+                     maintain_aspect = 0;
+size_t               cfg_auto_setbg = AUTOBG_OFF;
+int                  cfg_maintain_aspect = 0, cfg_randomize = 0;
+Window               zoom_win = None, config_win = None;
+int                  w = 3, h = 3;
 
 static char       **dirscan(char *dir, unsigned long *num);
 static char       **randomize_file_list(char **names, unsigned long num);
