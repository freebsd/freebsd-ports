--- src/Font.cc.orig	Fri Oct 25 23:07:07 2002
+++ src/Font.cc	Sun Nov 24 18:23:28 2002
@@ -140,7 +140,7 @@
 	if (name == 0)
 		return false;
 	bool ret_val = m_fontimp->load(name);
-	if (ret_val && name == 0) { //prevent from having a bad fontimp
+	if (ret_val && name != 0) { //prevent from having a bad fontimp
 		m_fontstr = name; // if the load really succeded then set font string
 	} else {
 		m_fontstr = "";
