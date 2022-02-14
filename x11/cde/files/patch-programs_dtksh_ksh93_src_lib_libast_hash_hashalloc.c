--- programs/dtksh/ksh93/src/lib/libast/hash/hashalloc.c.orig	2022-01-20 12:56:31.275926000 -0800
+++ programs/dtksh/ksh93/src/lib/libast/hash/hashalloc.c	2022-01-20 12:59:47.461533000 -0800
@@ -49,6 +49,9 @@
 	va_list*		vp = va;
 	Hash_region_f		region = 0;
 	void*			handle;
+#ifdef __powerpc64__
+	va_listarg		tmpval;
+#endif
 
 	va_start(ap, ref);
 
@@ -151,7 +154,12 @@
 				va_copy(*vp, ap);
 				vp++;
 			}
+#ifdef __powerpc64__
+			tmpval = va_listval(va_arg(ap, va_listarg));
+			va_copy(ap, tmpval);
+#else
 			va_copy(ap, va_listval(va_arg(ap, va_listarg)));
+#endif
 			break;
 		case 0:
 			if (vp > va)
