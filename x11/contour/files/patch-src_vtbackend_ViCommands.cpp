--- src/vtbackend/ViCommands.cpp.orig	2026-02-18 13:01:13 UTC
+++ src/vtbackend/ViCommands.cpp
@@ -34,12 +34,12 @@ namespace
         //
         // TODO: The punctuation test is highly inefficient. Adapt libunicode to allow O(1) access to these.
         return (codepoint > 255
-                && !(unicode::general_category::space_separator(codepoint)
-                     || unicode::general_category::initial_punctuation(codepoint)
-                     || unicode::general_category::final_punctuation(codepoint)
-                     || unicode::general_category::open_punctuation(codepoint)
-                     || unicode::general_category::close_punctuation(codepoint)
-                     || unicode::general_category::dash_punctuation(codepoint)))
+                && !(unicode::general_category::is_space_separator(codepoint)
+                     || unicode::general_category::is_initial_punctuation(codepoint)
+                     || unicode::general_category::is_final_punctuation(codepoint)
+                     || unicode::general_category::is_open_punctuation(codepoint)
+                     || unicode::general_category::is_close_punctuation(codepoint)
+                     || unicode::general_category::is_dash_punctuation(codepoint)))
                || (192 <= codepoint && codepoint <= 255);
     }
 
