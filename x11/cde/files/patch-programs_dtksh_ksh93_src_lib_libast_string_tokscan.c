--- programs/dtksh/ksh93/src/lib/libast/string/tokscan.c.orig	2022-01-20 12:56:38.679529000 -0800
+++ programs/dtksh/ksh93/src/lib/libast/string/tokscan.c	2022-01-20 13:02:26.179022000 -0800
@@ -188,6 +188,9 @@
 	char**		p_string;
 	char*		prv_f = 0;
 	va_list		prv_ap;
+#ifdef __powerpc64__
+	va_listarg	tmpval;
+#endif
 
 	va_start(ap, fmt);
 	if (!*s || *s == '\n')
@@ -233,7 +236,12 @@
 			prv_f = f;
 			f = va_arg(ap, char*);
 			va_copy(prv_ap, ap);
+#ifdef __powerpc64__
+			tmpval = va_listval(va_arg(ap, va_listarg));
+			va_copy(ap, tmpval);
+#else
 			va_copy(ap, va_listval(va_arg(ap, va_listarg)));
+#endif
 			continue;
 		case 'c':
 			p_char = va_arg(ap, char*);
