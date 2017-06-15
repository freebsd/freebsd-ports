From 5fd1276b8d024a5a2670ff60753c9760a2ff7ca7 Mon Sep 17 00:00:00 2001
From: Feng Chao <chaofeng111@gmail.com>
Date: Sun, 3 Aug 2014 21:18:52 +0800
Subject: Fix Bug 318453 - Blinking cursor of "fullwidth" character are
 "halfwidth"

Calculate the character width at current blinking cursor.

BUG: 318453
---
 src/TerminalDisplay.cpp | 4 +++-
 1 file changed, 3 insertions(+), 1 deletion(-)

diff --git src/TerminalDisplay.cpp src/TerminalDisplay.cpp
index 4d5bd8a..fd0f6b0 100644
--- src/TerminalDisplay.cpp
+++ src/TerminalDisplay.cpp
@@ -1600,7 +1600,9 @@ void TerminalDisplay::blinkCursorEvent()
 
 void TerminalDisplay::updateCursor()
 {
-    QRect cursorRect = imageToWidget(QRect(cursorPosition(), QSize(1, 1)));
+    int cursorLocation = loc(cursorPosition().x(), cursorPosition().y());
+    int charWidth = konsole_wcwidth(_image[cursorLocation].character);
+    QRect cursorRect = imageToWidget(QRect(cursorPosition(), QSize(charWidth, 1)));
     update(cursorRect);
 }
 
-- 
cgit v0.11.2

