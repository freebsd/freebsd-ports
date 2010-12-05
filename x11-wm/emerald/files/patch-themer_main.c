--- themer/main.c.orig	2009-10-13 20:56:23.000000000 -0400
+++ themer/main.c	2010-11-24 15:45:57.000000000 -0500
@@ -7,6 +7,103 @@
 #include <emerald.h>
 #include <engine.h>
 
+/* states: S_N: normal, S_I: comparing integral part, S_F: comparing
+           fractional parts, S_Z: idem but with leading Zeroes only */
+#define S_N    0x0
+#define S_I    0x4
+#define S_F    0x8
+#define S_Z    0xC
+
+/* result_type: CMP: return diff; LEN: compare using len_diff/diff */
+#define CMP    2
+#define LEN    3
+
+
+/* ISDIGIT differs from isdigit, as follows:
+   - Its arg may be any int or unsigned int; it need not be an unsigned char.
+   - It's guaranteed to evaluate its argument exactly once.
+   - It's typically faster.
+   Posix 1003.2-1992 section 2.5.2.1 page 50 lines 1556-1558 says that
+   only '0' through '9' are digits.  Prefer ISDIGIT to isdigit unless
+   it's important to use the locale's definition of `digit' even when the
+   host does not conform to Posix.  */
+#define ISDIGIT(c) ((unsigned) (c) - '0' <= 9)
+
+/* Compare S1 and S2 as strings holding indices/version numbers,
+   returning less than, equal to or greater than zero if S1 is less than,
+   equal to or greater than S2 (for more info, see the texinfo doc).
+*/
+
+int
+strverscmp (const char *s1, const char *s2)
+{
+  const unsigned char *p1 = (const unsigned char *) s1;
+  const unsigned char *p2 = (const unsigned char *) s2;
+  unsigned char c1, c2;
+  int state;
+  int diff;
+
+  /* Symbol(s)    0       [1-9]   others  (padding)
+     Transition   (10) 0  (01) d  (00) x  (11) -   */
+  static const unsigned int next_state[] =
+  {
+      /* state    x    d    0    - */
+      /* S_N */  S_N, S_I, S_Z, S_N,
+      /* S_I */  S_N, S_I, S_I, S_I,
+      /* S_F */  S_N, S_F, S_F, S_F,
+      /* S_Z */  S_N, S_F, S_Z, S_Z
+  };
+
+  static const int result_type[] =
+  {
+      /* state   x/x  x/d  x/0  x/-  d/x  d/d  d/0  d/-
+                 0/x  0/d  0/0  0/-  -/x  -/d  -/0  -/- */
+
+      /* S_N */  CMP, CMP, CMP, CMP, CMP, LEN, CMP, CMP,
+                 CMP, CMP, CMP, CMP, CMP, CMP, CMP, CMP,
+      /* S_I */  CMP, -1,  -1,  CMP,  1,  LEN, LEN, CMP,
+                  1,  LEN, LEN, CMP, CMP, CMP, CMP, CMP,
+      /* S_F */  CMP, CMP, CMP, CMP, CMP, LEN, CMP, CMP,
+                 CMP, CMP, CMP, CMP, CMP, CMP, CMP, CMP,
+      /* S_Z */  CMP,  1,   1,  CMP, -1,  CMP, CMP, CMP,
+                 -1,  CMP, CMP, CMP
+  };
+
+  if (p1 == p2)
+    return 0;
+
+  c1 = *p1++;
+  c2 = *p2++;
+  /* Hint: '0' is a digit too.  */
+  state = S_N | ((c1 == '0') + (ISDIGIT (c1) != 0));
+
+  while ((diff = c1 - c2) == 0 && c1 != '\0')
+    {
+      state = next_state[state];
+      c1 = *p1++;
+      c2 = *p2++;
+      state |= (c1 == '0') + (ISDIGIT (c1) != 0);
+    }
+
+  state = result_type[state << 2 | ((c2 == '0') + (ISDIGIT (c2) != 0))];
+
+  switch (state)
+    {
+    case CMP:
+      return diff;
+
+    case LEN:
+      while (ISDIGIT (*p1++))
+	if (!ISDIGIT (*p2++))
+	  return 1;
+
+      return ISDIGIT (*p2) ? -1 : diff;
+
+    default:
+      return state;
+    }
+}
+
 #define LAST_COMPAT_VER "0.1.0"
 
 typedef struct _FetcherInfo
@@ -264,6 +361,7 @@ static void info_dialog(gchar * val)
             GTK_DIALOG_DESTROY_WITH_PARENT,
             GTK_MESSAGE_INFO,
             GTK_BUTTONS_CLOSE,
+            "%s",
             val);
     gtk_dialog_run(GTK_DIALOG(w));
     gtk_widget_destroy(w);
@@ -275,6 +373,7 @@ static void error_dialog(gchar * val)
             GTK_DIALOG_DESTROY_WITH_PARENT,
             GTK_MESSAGE_ERROR,
             GTK_BUTTONS_CLOSE,
+            "%s",
             val);
     gtk_dialog_run(GTK_DIALOG(w));
     gtk_widget_destroy(w);
