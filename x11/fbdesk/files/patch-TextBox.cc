--- src/FbTk/TextBox.cc.orig	2006-03-25 15:42:00 UTC
+++ src/FbTk/TextBox.cc
@@ -199,7 +199,7 @@ void TextBox::buttonPressEvent(XButtonEv
         int delta = width();
         int tmp = 0;
         for(i = m_start_pos; i <= m_end_pos; i++) {
-            tmp = abs(event.x - font().textWidth(m_text.c_str() + m_start_pos, i - m_start_pos));
+            tmp = abs((int)(event.x - font().textWidth(m_text.c_str() + m_start_pos, i - m_start_pos)));
 
             if (tmp < delta) {
                 delta = tmp;
