--- src/Database.cpp.orig	2025-04-06 14:11:58 UTC
+++ src/Database.cpp
@@ -33,13 +33,13 @@ static inline std::string &ltrim(std::string &s) {

 // trim from start
 static inline std::string &ltrim(std::string &s) {
-        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
+        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](const unsigned char ch) {return !std::isspace(ch); }));
         return s;
 }

 // trim from end
 static inline std::string &rtrim(std::string &s) {
-        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
+        s.erase(std::find_if(s.rbegin(), s.rend(), [](const unsigned char ch) {return !std::isspace(ch); }).base(), s.end());
         return s;
 }

