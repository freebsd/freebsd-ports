--- src/rxvt.h.orig	2021-11-21 23:29:22 UTC
+++ src/rxvt.h
@@ -399,6 +399,12 @@ enum {
   C0_DLE, C0_DC1, C0_DC2, D0_DC3, C0_DC4, C0_NAK, C0_SYN, C0_ETB,
   C0_CAN, C0_EM , C0_SUB, C0_ESC, C0_IS4, C0_IS3, C0_IS2, C0_IS1,
 };
+
+struct string_term
+{
+  unsigned char v[3];
+};
+
 #define CHAR_ST                 0x9c    /* 0234 */
 
 /*
@@ -1366,11 +1372,11 @@ struct rxvt_term : zero_initialized, rxvt_vars, rxvt_s
   void process_escape_seq ();
   void process_csi_seq ();
   void process_window_ops (const int *args, unsigned int nargs);
-  char *get_to_st (unicode_t &ends_how);
+  char *get_to_st (string_term &st);
   void process_dcs_seq ();
   void process_osc_seq ();
-  void process_color_seq (int report, int color, const char *str, char resp);
-  void process_xterm_seq (int op, char *str, char resp);
+  void process_color_seq (int report, int color, const char *str, string_term &st);
+  void process_xterm_seq (int op, char *str, string_term &st);
   unsigned int map_rgb24_color (unsigned int r, unsigned int g, unsigned int b, unsigned int a);
   int privcases (int mode, unsigned long bit);
   void process_terminal_mode (int mode, int priv, unsigned int nargs, const int *arg);
