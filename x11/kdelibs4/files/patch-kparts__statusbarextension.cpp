commit 999eac446a49e6126df04aa8717f95e6aef136fc
Author: Andras Mantia <amantia@kde.org>
Date:   Thu Nov 10 11:40:22 2011 +0200

    Don't try to access the parent() from the destructor, fixes crash on destruction.
    BUG: 283657
    REVIEW: 103098

diff --git a/kparts/statusbarextension.cpp b/kparts/statusbarextension.cpp
index 7689360..96eb277 100644
--- ./kparts/statusbarextension.cpp
+++ ./kparts/statusbarextension.cpp
@@ -96,7 +96,7 @@ StatusBarExtension::StatusBarExtension(KParts::ReadOnlyPart *parent)
 
 StatusBarExtension::~StatusBarExtension()
 {
-  KStatusBar * sb = statusBar();
+  KStatusBar * sb = d->m_statusBar;
   for ( int i = d->m_statusBarItems.count () - 1; i >= 0 ; --i ) {
     if ( d->m_statusBarItems[i].widget() ) {
       if ( sb ) {
