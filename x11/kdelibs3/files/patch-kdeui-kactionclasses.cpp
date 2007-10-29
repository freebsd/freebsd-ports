--- kdeui/kactionclasses.cpp	2007/10/08 11:32:36	722993
+++ kdeui/kactionclasses.cpp	2007/10/20 20:49:01	727528
@@ -667,8 +667,8 @@
     KToolBar* bar = static_cast<KToolBar*>( widget );
     int id_ = KAction::getToolButtonID();
     bar->insertCombo( comboItems(), id_, isEditable(),
-                      SIGNAL( activated( int ) ), this,
-                      SLOT( slotActivated( int ) ), isEnabled(),
+                      SIGNAL( activated( const QString & ) ), this,
+                      SLOT( slotActivated( const QString & ) ), isEnabled(),
                       toolTip(), -1, index );
 
     QComboBox *cb = bar->getCombo( id_ );
