===================================================================
RCS file: /usr/repos/kde/kdebase/kxkb/kcmlayout.h,v
retrieving revision 1.22
retrieving revision 1.23
diff -u -p -r1.22 -r1.23
--- kxkb/kcmlayout.h	2003/10/29 07:30:36	1.22
+++ kxkb/kcmlayout.h	2004/06/28 14:19:03	1.23
@@ -54,7 +54,7 @@ protected slots:
   void variantChanged();
   void latinChanged();
   void layoutSelChanged(QListViewItem *);
-  void ruleChanged(const QString &rule);
+  void ruleChanged();
   void updateLayoutCommand();
   void updateOptionsCommand();
   void add();
@@ -71,7 +71,7 @@ private:
   QDict<OptionListItem> m_optionGroups;
   QDict<char> m_variants;
   QDict<char> m_includes;
-  QString m_rule;
+//  QString m_rule;
   KeyRules *m_rules;
 
   QWidget* makeOptionsTab();
