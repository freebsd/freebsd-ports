--- src/command.C.orig	2021-05-13 19:40:55 UTC
+++ src/command.C
@@ -57,6 +57,7 @@
 #endif
 
 #include <signal.h>
+#include <sys/param.h>
 
 #if LINUX_YIELD_HACK
 # include <time.h>
@@ -2368,7 +2369,9 @@ rxvt_term::next_char () noexcept
       if (len == (size_t)-2)
         {
           // the mbstate stores incomplete sequences. didn't know this :/
+#if __FreeBSD_version>502110
           cmdbuf_ptr = cmdbuf_endp;
+#endif
           break;
         }

@@ -3044,8 +3044,13 @@ rxvt_term::process_csi_seq ()
                 tt_printf ("%-.250s\012", rs[Rs_display_name]);
               break;
             case 8:			/* unofficial extension */
-              process_xterm_seq (XTerm_title, (char *)RESNAME "-" VERSION, CHAR_ST); // char * cast verified
-              break;
+              {
+                string_term st;
+                st.v[0] = CHAR_ST;
+                st.v[1] = '\0';
+                process_xterm_seq (XTerm_title, (char *)RESNAME "-" VERSION, st); // char * cast verified
+                break;
+              }
           }
         break;
 
@@ -3240,7 +3245,7 @@ char *
  * ends_how is terminator used. returned input must be free()'d
  */
 char *
-rxvt_term::get_to_st (unicode_t &ends_how)
+rxvt_term::get_to_st (string_term &st)
 {
   unicode_t ch;
   bool seen_esc = false;
@@ -3279,7 +3284,11 @@ rxvt_term::get_to_st (unicode_t &ends_how)
 
   string[n++] = '\0';
 
-  ends_how = (ch == 0x5c ? C0_ESC : ch);
+  n = 0;
+  if (ch == 0x5c)
+    st.v[n++] = C0_ESC;
+  st.v[n++] = ch;
+  st.v[n] = '\0';
 
   return rxvt_wcstombs (string);
 }
@@ -3295,8 +3304,8 @@ rxvt_term::process_dcs_seq ()
    * Not handled yet
    */
 
-  unicode_t eh;
-  char *s = get_to_st (eh);
+  string_term st;
+  char *s = get_to_st (st);
   if (s)
     free (s);
 
@@ -3318,12 +3327,12 @@ rxvt_term::process_osc_seq ()
 
   if (ch == ';')
     {
-      unicode_t eh;
-      char *s = get_to_st (eh);
+      string_term st;
+      char *s = get_to_st (st);
 
       if (s)
         {
-          process_xterm_seq (arg, s, eh);
+          process_xterm_seq (arg, s, st);
           free (s);
         }
     }
@@ -3433,7 +3442,7 @@ void
 }
 
 void
-rxvt_term::process_color_seq (int report, int color, const char *str, char resp)
+rxvt_term::process_color_seq (int report, int color, const char *str, string_term &st)
 {
   if (str[0] == '?' && !str[1])
     {
@@ -3449,9 +3458,9 @@ rxvt_term::process_color_seq (int report, int color, c
         snprintf (rgba_str, sizeof (rgba_str), "rgb:%04x/%04x/%04x", c.r, c.g, c.b);
 
       if (IN_RANGE_INC (color, minCOLOR, maxTermCOLOR))
-        tt_printf ("\033]%d;%d;%s%c", report, color - minCOLOR, rgba_str, resp);
+        tt_printf ("\033]%d;%d;%s%s", report, color - minCOLOR, rgba_str, st.v);
       else
-        tt_printf ("\033]%d;%s%c", report, rgba_str, resp);
+        tt_printf ("\033]%d;%s%s", report, rgba_str, st.v);
     }
   else
     set_window_color (color, str);
@@ -3461,7 +3470,7 @@ void
  * XTerm escape sequences: ESC ] Ps;Pt (ST|BEL)
  */
 void
-rxvt_term::process_xterm_seq (int op, char *str, char resp)
+rxvt_term::process_xterm_seq (int op, char *str, string_term &st)
 {
   int color;
   char *buf, *name;
@@ -3506,7 +3515,7 @@ rxvt_term::process_xterm_seq (int op, char *str, char 
                 && actual_format == 8)
               str = (const char *)(value);
 
-            tt_printf ("\033]%d;%s%c", op, option (Opt_insecure) ? str : "", resp);
+            tt_printf ("\033]%d;%s%s", op, option (Opt_insecure) ? str : "", st.v);
 
             XFree (value);
           }
@@ -3540,49 +3549,49 @@ rxvt_term::process_xterm_seq (int op, char *str, char 
             if ((buf = strchr (name, ';')) != NULL)
               *buf++ = '\0';
 
-            process_color_seq (op, color, name, resp);
+            process_color_seq (op, color, name, st);
           }
         break;
       case Rxvt_restoreFG:
       case XTerm_Color00:
-        process_color_seq (op, Color_fg, str, resp);
+        process_color_seq (op, Color_fg, str, st);
         break;
       case Rxvt_restoreBG:
       case XTerm_Color01:
-        process_color_seq (op, Color_bg, str, resp);
+        process_color_seq (op, Color_bg, str, st);
         break;
 #ifndef NO_CURSORCOLOR
       case XTerm_Color_cursor:
-        process_color_seq (op, Color_cursor, str, resp);
+        process_color_seq (op, Color_cursor, str, st);
         break;
 #endif
       case XTerm_Color_pointer_fg:
-        process_color_seq (op, Color_pointer_fg, str, resp);
+        process_color_seq (op, Color_pointer_fg, str, st);
         break;
       case XTerm_Color_pointer_bg:
-        process_color_seq (op, Color_pointer_bg, str, resp);
+        process_color_seq (op, Color_pointer_bg, str, st);
         break;
 #ifdef OPTION_HC
       case XTerm_Color_HC:
-        process_color_seq (op, Color_HC, str, resp);
+        process_color_seq (op, Color_HC, str, st);
         break;
       case XTerm_Color_HTC:
-        process_color_seq (op, Color_HTC, str, resp);
+        process_color_seq (op, Color_HTC, str, st);
         break;
 #endif
 #ifndef NO_BOLD_UNDERLINE_REVERSE
       case URxvt_Color_BD:
-        process_color_seq (op, Color_BD, str, resp);
+        process_color_seq (op, Color_BD, str, st);
         break;
       case URxvt_Color_UL:
-        process_color_seq (op, Color_UL, str, resp);
+        process_color_seq (op, Color_UL, str, st);
         break;
       case URxvt_Color_IT:
-        process_color_seq (op, Color_IT, str, resp);
+        process_color_seq (op, Color_IT, str, st);
         break;
 #endif
       case URxvt_Color_border:
-        process_color_seq (op, Color_border, str, resp);
+        process_color_seq (op, Color_border, str, st);
         break;
 
       case XTerm_logfile:
@@ -3610,10 +3619,10 @@ rxvt_term::process_xterm_seq (int op, char *str, char 
       case URxvt_boldItalicFont:
 #endif
         if (query)
-          tt_printf ("\33]%d;%-.250s%c", saveop,
+          tt_printf ("\33]%d;%-.250s%s", saveop,
                      option (Opt_insecure) && fontset[op - URxvt_font]->fontdesc
                        ? fontset[op - URxvt_font]->fontdesc : "",
-                     resp);
+                     st.v);
         else
           {
             const char *&res = rs[Rs_font + (op - URxvt_font)];
@@ -3626,23 +3635,23 @@ rxvt_term::process_xterm_seq (int op, char *str, char 
 
       case URxvt_version:
         if (query)
-          tt_printf ("\33]%d;rxvt-unicode;%-.20s;%c;%c%c",
+          tt_printf ("\33]%d;rxvt-unicode;%-.20s;%c;%c%s",
                      op,
                      rs[Rs_name], VERSION[0], VERSION[2],
-                     resp);
+                     st.v);
         break;
 
 #if !ENABLE_MINIMAL
       case URxvt_cellinfo:
         if (query)
-          tt_printf ("\33]%d;%d;%d;%d%c", saveop,
+          tt_printf ("\33]%d;%d;%d;%d%s", saveop,
                      fwidth, fheight, fbase,
-                     resp);
+                     st.v);
         break;
 
       case URxvt_locale:
         if (query)
-          tt_printf ("\33]%d;%-.250s%c", op, option (Opt_insecure) ? locale : "", resp);
+          tt_printf ("\33]%d;%-.250s%s", op, option (Opt_insecure) ? locale : "", st.v);
         else
           {
             set_locale (str);
@@ -3667,7 +3676,7 @@ rxvt_term::process_xterm_seq (int op, char *str, char 
 
 #if ENABLE_PERL
       case URxvt_perl:
-        HOOK_INVOKE ((this, HOOK_OSC_SEQ_PERL, DT_STR, str, DT_STR_LEN, &resp, 1, DT_END));
+        HOOK_INVOKE ((this, HOOK_OSC_SEQ_PERL, DT_STR, str, DT_STR, st.v, DT_END));
         break;
 #endif
     }
 
