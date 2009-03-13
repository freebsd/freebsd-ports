--- client.c.orig	2009-01-08 12:04:44.000000000 +0200
+++ client.c	2009-01-31 21:03:28.000000000 +0200
@@ -838,6 +838,11 @@ client_unmanage(client_t *c)
 {
     tag_array_t *tags = &globalconf.screens[c->screen].tags;
 
+    /* Reset transient_for attributes of widows that maybe refering to us */
+    for(client_t *tc = globalconf.clients; tc; tc = tc->next)
+        if(tc->transient_for == c)
+            tc->transient_for = NULL;
+
     if(globalconf.screens[c->phys_screen].client_focus == c)
         client_unfocus(c);
 
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
