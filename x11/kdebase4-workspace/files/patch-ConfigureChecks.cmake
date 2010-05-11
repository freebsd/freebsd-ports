--- ./ConfigureChecks.cmake.orig	2009-11-21 12:44:36.000000000 +0300
+++ ./ConfigureChecks.cmake	2010-01-27 00:04:40.445046695 +0300
@@ -16,16 +16,7 @@
     endmacro(define_pam_service)
 
     macro(install_pam_service APP)
-        string(TOUPPER KDE4_${APP}_PAM_SERVICE cvar)
-        install(CODE "
-            set(DESTDIR_VALUE \"\$ENV{DESTDIR}\")
-            if (NOT DESTDIR_VALUE)
-                exec_program(\"${KDEBASE_WORKSPACE_SOURCE_DIR}/mkpamserv\" ARGS ${${cvar}} RETURN_VALUE ret)
-                if (NOT ret)
-                    exec_program(\"${KDEBASE_WORKSPACE_SOURCE_DIR}/mkpamserv\" ARGS -P ${${cvar}}-np)
-                endif (NOT ret)
-            endif (NOT DESTDIR_VALUE)
-                    ")
+        message("Ignore installing pam service, FreeBSD has it already.")
     endmacro(install_pam_service)
 
     define_pam_service(KDM)
