--- src/gtk/notebook.cpp.orig	Sun Sep 21 18:31:57 2003
+++ src/gtk/notebook.cpp	Mon Nov 10 03:26:16 2003
@@ -643,7 +643,7 @@
     nb_page->m_text = text;
     if (nb_page->m_text.IsEmpty()) nb_page->m_text = wxT("");
   
-    nb_page->m_label = GTK_LABEL( gtk_label_new(nb_page->m_text.mbc_str()) );
+    nb_page->m_label = GTK_LABEL( gtk_label_new(wxGTK_CONV(nb_page->m_text)) );
     gtk_box_pack_end( GTK_BOX(nb_page->m_box), GTK_WIDGET(nb_page->m_label), FALSE, FALSE, m_padding );
   
     /* show the label */
