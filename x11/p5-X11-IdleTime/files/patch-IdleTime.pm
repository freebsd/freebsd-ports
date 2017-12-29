--- IdleTime.pm.orig	2008-07-04 17:02:22 UTC
+++ IdleTime.pm
@@ -13,7 +13,8 @@ use Inline (
 	C => 'DATA',
 	VERSION => '0.08',
 	NAME => 'X11::IdleTime',
-	LIBS => '-L/usr/X11R6/lib/ -lX11 -lXext -lXss',
+	INC => '-I/usr/local/include/',
+	LIBS => '-L/usr/local/lib/ -lX11 -lXext -lXss',
 	);
 
 1;
