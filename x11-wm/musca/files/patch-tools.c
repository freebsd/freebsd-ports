--- tools.c.orig	2009-11-03 02:20:21 UTC
+++ tools.c
@@ -227,7 +227,7 @@ ucell suck(FILE *src, byte *pad, ucell len, byte stop)
 	ucell ptr = 0;
 	for (;;)
 	{
-		byte c = fgetc(src);
+		int c = fgetc(src);
 		if (c == EOF)
 			break;
 
