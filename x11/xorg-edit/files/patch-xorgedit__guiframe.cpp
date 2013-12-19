--- xorgedit/guiframe.cpp.orig
+++ xorgedit/guiframe.cpp
@@ -182,8 +182,13 @@
   otherSectionTab = new wxPanel(layout);                       // iles/modules/extensions/dri tab panel
   wxBoxSizer *otherSectionTabSizer=new wxBoxSizer(wxVERTICAL);
 
+#ifdef __clang__
+  wxString *tempList = new wxString[devListSize+1];  // initial list for combo und choice elements
+  wxString *optList = new wxString[optListSize];   // initial list for option combo und choice elements
+#else
   wxString tempList[devListSize+1];  // initial list for combo und choice elements
   wxString optList[optListSize];   // initial list for option combo und choice elements
+#endif
 
   optList[0]=_("----------");
   optList[1]=_("Add Option");
@@ -821,6 +826,11 @@
     if (ShowError()) return;
   }
   SetSaved(true);
+
+#ifdef __clang__
+  delete[] optList;
+  delete[] tempList;
+#endif
 }
 
 const bool GuiFrame::CreateBackup(void) const
@@ -1832,8 +1842,13 @@
 
   warningText->SetLabel(_("Warning: Improper use of this tool can cause damage to your\nxorg.conf and may not start your Xserver.\nYou must restart X to take the changes effect."));
 
+#ifdef __clang__
+  wxString *tempList = new wxString[devListSize+1];  // initial list for combo und choice elements
+  wxString *optList = new wxString[optListSize];   // initial list for option combo und choice elements
+#else
   wxString tempList[devListSize+1];  // initial list for combo und choice elements
   wxString optList[optListSize];   // initial list for option combo und choice elements
+#endif
   unsigned int offset=0;
   unsigned int i;
 
@@ -2269,6 +2284,11 @@
 
   driBox->SetLabel(_("DRI"));
   return(false);
+
+#ifdef __clang__
+  delete[] optList;
+  delete[] tempList;
+#endif
 }
 
 void GuiFrame::SetSaved(const bool save)
