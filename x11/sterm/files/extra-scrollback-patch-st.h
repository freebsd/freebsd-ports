--- st.h.orig	2018-03-20 20:29:59 UTC
+++ st.h
@@ -3,6 +3,9 @@
 #include <stdint.h>
 #include <sys/types.h>
 
+/* Arbitrary size */
+#define HISTSIZE      2000
+
 /* macros */
 #define MIN(a, b)		((a) < (b) ? (a) : (b))
 #define MAX(a, b)		((a) < (b) ? (b) : (a))
@@ -19,6 +22,8 @@
 
 #define TRUECOLOR(r,g,b)	(1 << 24 | (r) << 16 | (g) << 8 | (b))
 #define IS_TRUECOL(x)		(1 << 24 & (x))
+#define TLINE(y)       ((y) < term.scr ? term.hist[((y) + term.histi - term.scr \
+               + HISTSIZE + 1) % HISTSIZE] : term.line[(y) - term.scr])
 
 enum glyph_attribute {
 	ATTR_NULL       = 0,
@@ -111,6 +116,9 @@ void *xmalloc(size_t);
 void *xrealloc(void *, size_t);
 char *xstrdup(char *);
 
+void kscrolldown(const Arg *);
+void kscrollup(const Arg *);
+
 /* config.h globals */
 extern char *utmp;
 extern char *stty_args;
