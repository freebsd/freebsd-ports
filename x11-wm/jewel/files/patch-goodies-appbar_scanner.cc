--- goodies/appbar/scanner.cc.orig	2007-12-06 20:49:35.000000000 +0100
+++ goodies/appbar/scanner.cc	2007-12-06 20:50:28.000000000 +0100
@@ -156,7 +156,7 @@
 {
 	s_token.empty();	
 
-	while(char_class[character]==type)
+	while(char_class[(int) character]==type)
 	{
 		s_token += character;
 
@@ -177,7 +177,7 @@
 		if (!spaces) {
 			char_class[' ']=whitespace;	
 
-			while(char_class[character]==whitespace)
+			while(char_class[(int)character]==whitespace)
 			{
 				if( inputFile.eof() ) return;
 		
@@ -192,7 +192,7 @@
 		}
 	}
 
-	if (! inputFile.eof() ) { concat( char_class[character] ); }
+	if (! inputFile.eof() ) { concat( char_class[(int)character] ); }
 }
 
 bool Scanner::match( std::string m )
