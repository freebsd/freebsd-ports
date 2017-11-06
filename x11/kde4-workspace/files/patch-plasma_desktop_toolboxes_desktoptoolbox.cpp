* Hide the desktop toolbox (aka "cashew") when widgets are locked
*
--- plasma/desktop/toolboxes/desktoptoolbox.cpp.orig	2015-06-26 03:17:21 UTC
+++ plasma/desktop/toolboxes/desktoptoolbox.cpp
@@ -177,6 +177,8 @@ void DesktopToolBox::init()
     connect(Plasma::Theme::defaultTheme(), SIGNAL(themeChanged()),
             this, SLOT(updateTheming()));
     Plasma::ToolTipManager::self()->registerWidget(this);
+    QObject::connect(m_containment, SIGNAL(immutabilityChanged(Plasma::ImmutabilityType)),
+                     this, SLOT(immutabilityChanged(Plasma::ImmutabilityType)));
 
     if (KAuthorized::authorizeKAction("logout")) {
         QAction *action = new QAction(i18n("Leave..."), this);
@@ -761,6 +763,11 @@ void DesktopToolBox::toggle()
     setShowing(!isShowing());
 }
 
+void DesktopToolBox::immutabilityChanged(Plasma::ImmutabilityType immutability)
+{
+    setVisible(immutability == Plasma::Mutable);
+}
+
 void DesktopToolBox::adjustBackgroundBorders() const
 {
     Plasma::FrameSvg *background = const_cast<Plasma::FrameSvg *>(m_background);
