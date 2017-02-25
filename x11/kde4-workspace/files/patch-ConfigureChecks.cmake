--- ConfigureChecks.cmake.orig	2015-06-26 03:17:21 UTC
+++ ConfigureChecks.cmake
@@ -21,16 +21,7 @@ if (PAM_FOUND)
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
