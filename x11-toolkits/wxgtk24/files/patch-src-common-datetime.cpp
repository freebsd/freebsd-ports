--- src/common/datetime.cpp.orig	Tue Nov  4 09:50:09 2003
+++ src/common/datetime.cpp	Tue Nov  4 09:52:02 2003
@@ -349,6 +349,35 @@
     return wxString(buf);
 }
 
+#ifdef HAVE_STRPTIME
+  	 
+// Unicode-friendly strptime() wrapper
+static const wxChar *
+CallStrptime(const wxChar *input, const char *fmt, tm *tm)
+{
+    // the problem here is that strptime() returns pointer into the string we
+    // passed to it while we're really interested in the pointer into the
+    // original, Unicode, string so we try to transform the pointer back
+#if wxUSE_UNICODE
+    wxCharBuffer inputMB(wxConvertWX2MB(input));
+#else // ASCII
+    const char * const inputMB = input;
+#endif // Unicode/Ascii
+
+    const char *result = strptime(inputMB, fmt, tm);
+    if ( !result )
+        return NULL;
+  	 
+#if wxUSE_UNICODE
+    // FIXME: this is wrong in presence of surrogates &c
+    return input + (result - inputMB.data());
+#else // ASCII
+    return result;
+#endif // Unicode/Ascii
+}
+
+#endif // HAVE_STRPTIME
+
 // if year and/or month have invalid values, replace them with the current ones
 static void ReplaceDefaultYearMonthWithCurrent(int *year,
                                                wxDateTime::Month *month)
@@ -2920,7 +2949,7 @@
                 // to our generic code anyhow (FIXME !Unicode friendly)
                 {
                     struct tm tm;
-                    const wxChar *result = strptime(input, "%x", &tm);
+                    const wxChar *result = CallStrptime(input, "%x", &tm);
                     if ( result )
                     {
                         input = result;
@@ -2985,7 +3014,7 @@
                 {
                     // use strptime() to do it for us (FIXME !Unicode friendly)
                     struct tm tm;
-                    input = strptime(input, "%X", &tm);
+                    input = CallStrptime(input, "%X", &tm);
                     if ( !input )
                     {
                         return (wxChar *)NULL;
