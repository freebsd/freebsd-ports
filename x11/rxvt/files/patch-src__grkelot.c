--- src/grkelot.c
+++ src/grkelot.c
@@ -80,10 +80,6 @@
 #define MAX_SWITCHER	2U	/* per state */
 #define MAX_VAL 	256	/* for temp allocation */
 
-typedef unsigned char u_char;
-typedef unsigned int u_int;
-typedef unsigned long u_long;
-
 typedef struct s_xlat {
     u_int           first, last;
     u_int          *pval;	/* array of translated values */
@@ -158,9 +154,9 @@
 
 #define NUM_XLAT_TYPES	(sizeof(xlat_type) / sizeof(xlat_type[0]))
 
-static void     kstate_add_xlat(char *str);
-static void     kstate_add_switcher(char *str);
-static void     kstate_set_life(char *str);
+void     kstate_add_xlat(char *str);
+void     kstate_add_switcher(char *str);
+void     kstate_set_life(char *str);
 
 /* --- Functions ------------- */
 /* INTPROTO */
