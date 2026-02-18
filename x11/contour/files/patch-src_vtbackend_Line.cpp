--- src/vtbackend/Line.cpp.orig	2026-02-18 12:56:38 UTC
+++ src/vtbackend/Line.cpp
@@ -174,7 +174,7 @@ InflatedLineBuffer<Cell> inflate(TrivialLineBuffer con
         auto const nextChar =
             holds_alternative<unicode::Success>(r) ? get<unicode::Success>(r).value : ReplacementCharacter;
 
-        if (unicode::grapheme_segmenter::breakable(lastChar, nextChar))
+        if (unicode::grapheme_segmenter::is_breakable(lastChar, nextChar))
         {
             while (gapPending > 0)
             {
