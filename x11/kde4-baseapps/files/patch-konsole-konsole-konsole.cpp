--- konsole/konsole/konsole.cpp	16 Nov 2004 16:46:00 -0000	1.472.2.6
+++ konsole/konsole/konsole.cpp	1 Dec 2004 17:05:30 -0000	1.472.2.7
@@ -2381,11 +2381,11 @@ void Konsole::addSession(TESession* s)
     createSessionTab(te, SmallIconSet(s->IconName()), newTitle);
     setSchema(s->schemaNo());
     tabwidget->setCurrentPage(tabwidget->count()-1);
-      disableMasterModeConnections(); // no duplicate connections, remove old
-      enableMasterModeConnections();
-    }
-    if( tabwidget )
-    m_removeSessionButton->setEnabled(tabwidget->count()>1);
+    disableMasterModeConnections(); // no duplicate connections, remove old
+    enableMasterModeConnections();
+    if(m_removeSessionButton)
+      m_removeSessionButton->setEnabled(tabwidget->count()>1);
+  }
 }
 
 QString Konsole::currentSession()
@@ -2827,8 +2827,8 @@ void Konsole::doneSession(TESession* s)
       rootxpms.remove(s->widget());
     }
     delete s->widget();
-    if( tabwidget )
-    m_removeSessionButton->setEnabled(tabwidget->count()>1);
+    if (m_removeSessionButton)
+      m_removeSessionButton->setEnabled(tabwidget->count()>1);
   }
   session2action.remove(s);
   action2session.remove(ra);
