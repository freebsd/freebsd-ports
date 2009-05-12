--- build-utils/gperf.sh.orig
+++ build-utils/gperf.sh
@@ -1,4 +1,4 @@
-#! /bin/sh -e
+#!/bin/sh
 #
 # Copyright © 2008 Pierre Habouzit <madcoder@debian.org>
 #
@@ -50,7 +50,7 @@ do_h() {
 
 typedef enum awesome_token_t {
     A_TK_UNKNOWN,
-`tr 'a-z-./ ' 'A-Z____' | sed -e "s/^[^/].*/    A_TK_&,/"`
+`tr '[:lower:]' '[:upper:]' | sed -e "s/^[^/].*/    A_TK_&,/"`
 } awesome_token_t;
 
 __attribute__((pure)) enum awesome_token_t a_tokenize(const char *s, int len);
@@ -63,20 +63,21 @@ do_tokens() {
         case "$tok" in
             "") continue;;
             *)
-                echo "$tok, A_TK_`echo $tok | tr 'a-z-./ ' 'A-Z____'`"
+                echo "$tok, A_TK_`echo $tok | tr '[:lower:]' '[:upper:]'`"
                 ;;
         esac
     done
 }
 
 do_c() {
-    if ! which gperf > /dev/null; then
+    which gperf > /dev/null
+    if test $? = 1 ; then
         echo "gperf not found. You need to install gperf." > /dev/stderr;
         exit 1;
     fi;
 
-    cat <<EOF | gperf -l -t -C -F",0" \
-        --language=ANSI-C -Na_tokenize_aux \
+    gperf -l -t -C -F",0" \
+        --language=ANSI-C -Na_tokenize_aux <<EOF \
         | sed -e '/__gnu_inline__/d;s/\<\(__\|\)inline\>//g'
 %{
 `do_hdr`
@@ -119,8 +120,8 @@ trap "rm -f ${TARGET}" 0
 
 rm -f "${TARGET}"
 case "${TARGET}" in
-    *.h) cat "${TOKENS_FILE}" | do_h > "${TARGET}";;
-    *.c) cat "${TOKENS_FILE}" | do_c > "${TARGET}";;
+    *.h) do_h > "${TARGET}" < "${TOKENS_FILE}" ;;
+    *.c) do_c > "${TARGET}" < "${TOKENS_FILE}" ;;
     *)  die "you must ask for the 'h' or 'c' generation";;
 esac
 chmod -w "${TARGET}"
