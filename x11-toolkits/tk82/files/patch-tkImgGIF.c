--- ../generic/tkImgGIF.c.orig	1999-07-01 02:39:44.000000000 +0200
+++ ../generic/tkImgGIF.c	2011-09-03 18:20:45.000000000 +0200
@@ -666,7 +666,7 @@
 			ypos += 2; break;
 		}
 		
-		while (ypos >= height) {
+		while (ypos >= rows) {
 		    ++pass;
 		    switch (pass) {
 			case 1:
