diff -u -r src/fluxbox.hh.orig src/fluxbox.hh
--- src/fluxbox.hh.orig	Sat Dec  7 09:15:26 2002
+++ src/fluxbox.hh	Mon Oct 27 23:34:49 2003
@@ -184,7 +184,7 @@
 
 #ifndef	 HAVE_STRFTIME
 
-	enum { B_AMERICANDATE = 1, B_EUROPEANDATE };
+	enum { B_AmericanDate = 1, B_EuropeanDate };
 #endif // HAVE_STRFTIME
 	
 	typedef std::vector<Fluxbox::Titlebar> TitlebarList;
