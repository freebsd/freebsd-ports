===================================================================
RCS file: /usr/repos/kde/kdebase/kxkb/kcmlayout.cpp,v
retrieving revision 1.82.2.1
retrieving revision 1.86
diff -u -p -r1.82.2.1 -r1.86
--- kxkb/kcmlayout.cpp	2004/05/19 12:09:58	1.82.2.1
+++ kxkb/kcmlayout.cpp	2004/06/28 14:19:03	1.86
@@ -79,7 +79,8 @@ OptionListItem * OptionListItem::findChi
 }
 
 LayoutConfig::LayoutConfig(QWidget *parent, const char *name)
-  : KCModule(parent, name), m_rules(0)
+  : KCModule(parent, name), 
+    m_rules(NULL)
 {
   QVBoxLayout *main = new QVBoxLayout(this, 0, KDialog::spacingHint());
 
@@ -122,7 +124,7 @@ LayoutConfig::LayoutConfig(QWidget *pare
 #endif
 
   //Read rules - we _must_ read _before_ creating xkb-options comboboxes
-  ruleChanged("xfree86");
+  ruleChanged();
 
   makeOptionsTab();
 
@@ -292,6 +294,8 @@ QWidget* LayoutConfig::makeOptionsTab()
   connect(listView, SIGNAL(clicked(QListViewItem *)), SLOT(changed()));
   connect(listView, SIGNAL(clicked(QListViewItem *)), SLOT(updateOptionsCommand()));
 
+  connect(widget->chkEnableOptions, SIGNAL(toggled(bool)), SLOT(changed()));
+
   connect(widget->checkResetOld, SIGNAL(toggled(bool)), SLOT(changed()));
   connect(widget->checkResetOld, SIGNAL(toggled(bool)), SLOT(updateOptionsCommand()));
 
@@ -405,10 +409,10 @@ void LayoutConfig::load()
   bool use = config->readBoolEntry( "Use", false );
 
   // find out which rule applies
-  QString rule = "xfree86"; //config->readEntry("Rule", "xfree86");
+  //QString rule = "xfree86"; //config->readEntry("Rule", "xfree86");
 
   // update other files
-  ruleChanged(rule);
+  ruleChanged();
 
   // find out about the model
   QString model = config->readEntry("Model", "pc104");
@@ -499,12 +506,12 @@ void LayoutConfig::load()
   emit KCModule::changed( false );
 }
 
-void LayoutConfig::ruleChanged(const QString &rule)
+void LayoutConfig::ruleChanged()
 {
-  if( rule == m_rule )
-    return;
+//  if( rule == m_rule )
+//    return;
 
-  m_rule = rule;
+//  m_rule = rule;
 
   QString model; //, layout;
   if (m_rules)
@@ -514,7 +521,7 @@ void LayoutConfig::ruleChanged(const QSt
     }
 
   delete m_rules;
-  m_rules = new KeyRules(rule);
+  m_rules = new KeyRules();
 
   QStringList tmp;
   widget->comboModel->clear();
@@ -672,7 +680,7 @@ void LayoutConfig::save()
 void LayoutConfig::defaults()
 {
   widget->chkEnable->setChecked(false);
-  ruleChanged("xfree86");
+  ruleChanged();
 
   widget->comboModel->setCurrentText("pc104");
   //layoutCombo->setCurrentText("us");
