--- IdleTime.pm.orig	Fri Feb  7 23:22:42 2003
+++ IdleTime.pm	Wed Jul  9 18:23:01 2003
@@ -12,6 +12,7 @@
 	C => 'DATA',
 	VERSION => '0.01',
 	NAME => 'X11::IdleTime',
+	INC => '-I/usr/X11R6/include/',
 	LIBS => '-L/usr/X11R6/lib/ -lX11 -lXext -lXss',
 	);
 
