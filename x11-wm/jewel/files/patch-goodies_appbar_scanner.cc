--- goodies/appbar/scanner.cc.orig	2005-01-03 21:54:58 UTC
+++ goodies/appbar/scanner.cc
@@ -156,7 +156,7 @@ void Scanner::concat(int type)
 {
 	s_token.empty();	
 
-	while(char_class[character]==type)
+	while(char_class[(int) character]==type)
 	{
 		s_token += character;
 
@@ -177,7 +177,7 @@ void Scanner::getNextToken(bool spaces) 
 		if (!spaces) {
 			char_class[' ']=whitespace;	
 
-			while(char_class[character]==whitespace)
+			while(char_class[(int)character]==whitespace)
 			{
 				if( inputFile.eof() ) return;
 		
@@ -192,7 +192,7 @@ void Scanner::getNextToken(bool spaces) 
 		}
 	}
 
-	if (! inputFile.eof() ) { concat( char_class[character] ); }
+	if (! inputFile.eof() ) { concat( char_class[(int)character] ); }
 }
 
 bool Scanner::match( std::string m )
