--- src/Tab.cc.orig	Tue Feb 25 03:00:22 2003
+++ src/Tab.cc	Tue Feb 25 03:01:31 2003
@@ -1011,14 +1011,14 @@
 	Fluxbox *fluxbox = Fluxbox::instance();
 	if (m_prev) {	//if this have a chain to "the left" (previous tab) then set it's next to this next
 		m_prev->m_next = m_next;
-		if(!m_next && !fluxbox->useTabs())//Only two tabs in list, remove tab from remaining window
+		if(!m_next && !m_prev->m_prev && !fluxbox->useTabs())//Only two tabs in list, remove tab from remaining window
 			m_prev->m_win->setTab(false);
 		else
 			tmp = m_prev;
 	} 
 	if (m_next) {	//if this have a chain to "the right" (next tab) then set it's prev to this prev
 		m_next->m_prev = m_prev;
-		if(!m_prev && !fluxbox->useTabs())//Only two tabs in list, remove tab from remaining window
+		if(!m_prev && !m_next->m_next && !fluxbox->useTabs())//Only two tabs in list, remove tab from remaining window
 			m_next->m_win->setTab(false);
 		else
 			tmp = m_next;
