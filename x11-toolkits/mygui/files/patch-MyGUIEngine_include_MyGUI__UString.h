--- MyGUIEngine/include/MyGUI_UString.h.orig	2023-05-09 09:46:12 UTC
+++ MyGUIEngine/include/MyGUI_UString.h
@@ -164,10 +164,10 @@ namespace MyGUI
 		static const size_type npos = static_cast<size_type>(~0);
 
 		//! a single 32-bit Unicode character
-		using unicode_char = uint32;
+		using unicode_char = char32_t;
 
 		//! a single UTF-16 code point
-		using code_point = uint16;
+		using code_point = char16_t;
 
 		//! value type typedef for use in iterators
 		using value_type = code_point;
