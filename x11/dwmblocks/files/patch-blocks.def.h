--- blocks.def.h.orig	2020-12-27 20:43:03 UTC
+++ blocks.def.h
@@ -1,9 +1,8 @@
 //Modify this file to change what commands output to your statusbar, and recompile using the make command.
 static const Block blocks[] = {
-	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
-	{"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},
-
-	{"", "date '+%b %d (%a) %I:%M%p'",					5,		0},
+	/*Icon*/	/*Command*/								/*Update Interval*/	/*Update Signal*/
+	{"", "uname -n | sed 's/^/ /'",								0,				0},
+	{"", "date '+%F %R'",									60,				0},
 };
 
 //sets delimeter between status commands. NULL character ('\0') means no delimeter.
