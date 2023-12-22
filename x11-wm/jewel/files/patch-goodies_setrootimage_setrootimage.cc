--- goodies/setrootimage/setrootimage.cc.orig	2005-01-03 21:54:58 UTC
+++ goodies/setrootimage/setrootimage.cc
@@ -31,6 +31,9 @@
  * Released under the GNU GPL license
  * www.gnu.org
  */
+#include <iostream>
+using namespace std;
+
 #include <X11/Xlib.h>
 #include <X11/xpm.h>
 #include <stdlib.h>
@@ -56,10 +59,11 @@ BColor parseCommandlineColor(char* the_color)
 		temp_blue[1] = the_color[i];
 	}
 
-	color.red = strtol(temp_red,0,16);
+	color.pixel = 0;
+   color.red = strtol(temp_red,0,16);
 	color.green = strtol(temp_green,0,16);
 	color.blue = strtol(temp_blue,0,16);
-	
+
 	return color;
 }
 
@@ -86,10 +90,10 @@ int main (int argc, char * argv[])
 	Pixmap root_pix = None;
 	BColor to, from;
 	
-	char* opt_color="no color";
-	char* opt_from="708090";
-	char* opt_to="ffffff"; 
-	char* opt_display="";
+	char* opt_color=(char *)"no color";
+	char* opt_from=(char *)"708090";
+	char* opt_to=(char *)"ffffff"; 
+	char* opt_display=(char *)"";
 
 	int width=0;
 	int height=0;
