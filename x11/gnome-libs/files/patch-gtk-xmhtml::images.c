
$FreeBSD$

--- gtk-xmhtml/images.c	2001/12/15 05:19:03	1.1
+++ gtk-xmhtml/images.c	2001/12/15 05:19:22
@@ -2393,7 +2393,7 @@
 		{
 			if(!html->html.xcc)
 				_XmHTMLCheckXCC(html);
-			image->xcc = html->html.xcc;
+			xcc = image->xcc = html->html.xcc;
 		}
 	}
 
