--- kdeprint/management/smbview.cpp	2007-08-30 19:42:25.000000000 -0700
+++ kdeprint/management/smbview.cpp.old	2007-08-30 19:43:50.000000000 -0700
@@ -179,7 +179,7 @@
 			m_current = item;
 			*m_proc << "nmblookup"+m_wins_server+"-M ";
                         *m_proc << KProcess::quote(item->text(0));
-                        *m_proc << " -S | grep '<20>' | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*<20>.*//' | xargs -iserv_name smbclient -N -L 'serv_name' -W ";
+                        *m_proc << " -S | grep '<20>' | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*<20>.*//' | xargs -Iserv_name smbclient -N -L 'serv_name' -W ";
                         *m_proc << KProcess::quote(item->text(0));
 			*m_proc << " -A ";
                         *m_proc << KProcess::quote(m_passwdFile->name());
