--- src/vtbackend/Screen.cpp.orig	2026-02-18 12:52:30 UTC
+++ src/vtbackend/Screen.cpp
@@ -544,7 +544,7 @@ void Screen<Cell>::writeTextInternal(char32_t sourceCo
 
     char32_t const codepoint = _cursor.charsets.map(sourceCodepoint);
 
-    if (unicode::grapheme_segmenter::breakable(_terminal->parser().precedingGraphicCharacter(), codepoint))
+    if (unicode::grapheme_segmenter::is_breakable(_terminal->parser().precedingGraphicCharacter(), codepoint))
     {
         writeCharToCurrentAndAdvance(codepoint);
     }
