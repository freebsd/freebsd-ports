--- programs/dtksh/ksh93/src/lib/libast/hash/hashalloc.c.orig	2021-12-13 19:03:46 UTC
+++ programs/dtksh/ksh93/src/lib/libast/hash/hashalloc.c
@@ -49,6 +49,7 @@ hashalloc(Hash_table_t* ref, ...)
 	va_list*		vp = va;
 	Hash_region_f		region = 0;
 	void*			handle;
+	va_listarg		tmpval;
 
 	va_start(ap, ref);
 
@@ -151,7 +152,8 @@ hashalloc(Hash_table_t* ref, ...)
 				va_copy(*vp, ap);
 				vp++;
 			}
-			va_copy(ap, va_listval(va_arg(ap, va_listarg)));
+			tmpval = va_listval(va_arg(ap, va_listarg));
+			va_copy(ap, tmpval);
 			break;
 		case 0:
 			if (vp > va)
