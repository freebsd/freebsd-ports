--- ./lib/libxview/textsw/txt_again.c.orig	Tue Jun 29 07:17:32 1993
+++ ./lib/libxview/textsw/txt_again.c	Sat Apr  1 18:25:29 2000
@@ -28,6 +28,8 @@ Pkg_private CHAR    *STRNCPY();
 Pkg_private Es_index textsw_do_input();
 Pkg_private Es_index textsw_do_pending_delete();
 
+static int textsw_string_min_free();
+
 string_t        null_string = {0, 0, 0};
 
 #define	TEXT_DELIMITER	"\\"
@@ -182,6 +184,7 @@ textsw_string_min_free(ptr_to_string, mi
  * Following is stolen from 3.2ALPHA sprintf(str, fmt, va_alist) SIDE_EFFECT:
  * TXTSW_STRING_FREE(ptr_to_string) is modified by this routine.
  */
+#ifndef __FreeBSD__
 #ifndef SVR4
 
 /* VARARGS2 */
@@ -325,6 +328,31 @@ va_dcl
 
 #endif /* SVR4 */
 
+#else /* __FreeBSD__ */
+/*inspiration taken from sprintf.c */
+
+static int
+textsw_printf(register string_t *ptr_to_string, char  *fmt, ...)
+{ 
+    FILE            _strbuf;
+    int             result;
+    va_list         args;
+    _strbuf._flags = __SWR | __SSTR;
+    _strbuf._bf._base = _strbuf._p = (char *) TXTSW_STRING_FREE(ptr_to_string);
+    _strbuf._bf._size = _strbuf._w = ptr_to_string->max_length - TXTSW_STRING_LENGTH(ptr_to_string);
+    VA_START(args, fmt);
+    result = vfprintf (&_strbuf, fmt, args);
+    va_end(args);
+    TXTSW_STRING_FREE(ptr_to_string) = (char *) _strbuf._p;
+#ifndef lint
+    if (result >= 0)
+    putc('\0', &_strbuf);
+#endif
+    return (result); 
+}
+
+#endif /* __FreeBSD__ */
+
 static	void
 textsw_record_buf(again, buffer, buffer_length)
     register string_t *again;
@@ -619,6 +647,8 @@ textsw_record_trash_insert(textsw)
  */
 /* VARARGS2 */
 
+#ifndef __FreeBSD__
+
 static int
 #ifdef ANSI_FUNC_PROTO
 textsw_scanf(register string_t *ptr_to_string, register char  *fmt, ...)
@@ -705,6 +735,39 @@ va_dcl
 
 #endif /* OW_I18N */
 }
+#else /* __FreeBSD__ */
+/*inspiration/code taken from sscanf.c */
+
+static int
+eofread(cookie, buf, len)
+        void *cookie;
+        char *buf;
+        int len;
+{
+
+        return (0);
+}   
+
+static int
+textsw_scanf(register string_t *ptr_to_string, char  *fmt, ...)
+{
+    FILE            _strbuf;
+    int             result;
+    va_list         args;
+
+    _strbuf._flags = __SRD;
+    _strbuf._bf._base = _strbuf._p = (char *) TXTSW_STRING_BASE(ptr_to_string);
+    _strbuf._bf._size = _strbuf._r = TXTSW_STRING_LENGTH(ptr_to_string);
+    _strbuf._read = eofread;
+    _strbuf._ub._base = NULL;
+    _strbuf._lb._base = NULL;
+    VA_START(args, fmt);
+    result = __svfscanf(&_strbuf, fmt, args);
+    va_end(args);
+    TXTSW_STRING_BASE(ptr_to_string) = (char *) _strbuf._p;
+    return (result);
+}       
+#endif /* __FreeBSD__ */
 
 static int
 textsw_next_is_delimiter(again)
