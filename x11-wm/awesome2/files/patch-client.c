--- client.c.orig	2009-01-08 12:04:44.000000000 +0200
+++ client.c	2009-01-31 21:03:28.000000000 +0200
@@ -1455,7 +1455,7 @@
                                    xcb_get_wm_class_unchecked(globalconf.connection, (*c)->win),
                                    &hint, NULL))
              return 0;
-        lua_pushstring(L, hint.class);
+        lua_pushstring(L, hint.class_name);
         xcb_get_wm_class_reply_wipe(&hint);
         break;
       case A_TK_INSTANCE:
@@ -1463,7 +1463,7 @@
                                    xcb_get_wm_class_unchecked(globalconf.connection, (*c)->win),
                                    &hint, NULL))
             return 0;
-        lua_pushstring(L, hint.name);
+        lua_pushstring(L, hint.instance_name);
         xcb_get_wm_class_reply_wipe(&hint);
         break;
       case A_TK_ROLE:
