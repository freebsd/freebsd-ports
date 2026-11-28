--- poweroff.lisp.orig	2026-11-28 07:45:15 UTC
+++ poweroff.lisp
@@ -52,13 +52,7 @@
       (t
        (message "^1ERROR:~%Suspend is not available on your system.^*"))))
   #+bsd
-  (dbus:with-open-bus (bus (dbus:system-server-addresses))
-    (if (find "org.freedesktop.ConsoleKit" (list-names bus) :test #'string=)
-        (dbus:with-introspected-object (login bus "/org/freedesktop/ConsoleKit" "org.freedesktop.ConsoleKit")
-          (if (string= "yes" (login "org.freedesktop.login1.Manager" "CanSuspend"))
-              (login "org.freedesktop.ConsoleKit.Manager" "Suspend" nil)
-              (message "^1ERROR:~%Suspend is not available on your system.^*")))
-        (message "^1ERROR:~%Suspend is not available on your system.^*"))))
+  (run-shell-command "zzz"))
 
 (defcommand hibernate () ()
   "Hibernates the system."
@@ -80,11 +74,5 @@
       (t
        (message "^1ERROR:~%Hibernate is not available on your system.^*"))))
   #+bsd
-  (dbus:with-open-bus (bus (dbus:system-server-addresses))
-    (if (find "org.freedesktop.ConsoleKit" (list-names bus) :test #'string=)
-        (dbus:with-introspected-object (login bus "/org/freedesktop/ConsoleKit" "org.freedesktop.ConsoleKit")
-          (if (string= "yes" (login "org.freedesktop.login1.Manager" "CanHibernate"))
-              (login "org.freedesktop.ConsoleKit.Manager" "Hibernate" nil)
-              (message "^1ERROR:~%Hibernate is not available on your system.^*")))
-        (message "^1ERROR:~%Hibernate is not available on your system.^*"))))
+  (message "^1ERROR:~%Hibernate is not available on your system.^*"))
 
