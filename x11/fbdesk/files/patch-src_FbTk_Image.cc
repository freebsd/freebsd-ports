--- src/FbTk/Image.cc.orig	2018-08-28 13:45:07 UTC
+++ src/FbTk/Image.cc
@@ -85,14 +85,14 @@ PixmapWithMask *Image::load(const std::string &filenam
 
 
     if (filename == "")
-        return false;
+        return NULL;
 
     // determine file ending
     std::string extension(StringUtil::toUpper(StringUtil::findExtension(filename)));
     
     // valid handle?
     if (s_image_map.find(extension) == s_image_map.end())
-        return false;
+        return NULL;
     
     // load file
     PixmapWithMask *pm = s_image_map[extension]->load(filename, screen_num);
