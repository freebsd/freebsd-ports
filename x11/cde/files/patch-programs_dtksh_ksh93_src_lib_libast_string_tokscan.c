--- programs/dtksh/ksh93/src/lib/libast/string/tokscan.c.orig	2021-12-13 22:46:02 UTC
+++ programs/dtksh/ksh93/src/lib/libast/string/tokscan.c
@@ -188,6 +188,7 @@ tokscan(register char* s, char** nxt, const char* fmt,
 	char**		p_string;
 	char*		prv_f = 0;
 	va_list		prv_ap;
+	va_listarg	tmpval;
 
 	va_start(ap, fmt);
 	if (!*s || *s == '\n')
@@ -233,7 +234,8 @@ tokscan(register char* s, char** nxt, const char* fmt,
 			prv_f = f;
 			f = va_arg(ap, char*);
 			va_copy(prv_ap, ap);
-			va_copy(ap, va_listval(va_arg(ap, va_listarg)));
+			tmpval = va_listval(va_arg(ap, va_listarg));
+			va_copy(ap, tmpval);
 			continue;
 		case 'c':
 			p_char = va_arg(ap, char*);
