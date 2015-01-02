diff --git src/wmmgr.cc src/wmmgr.cc
index 4252bf6..dc1e703 100644
--- src/wmmgr.cc
+++ src/wmmgr.cc
@@ -697,7 +697,7 @@ void YWindowManager::handleClientMessage(const XClientMessageEvent &message) {
         case ICEWM_ACTION_RESTARTWM:
         case ICEWM_ACTION_WINDOWLIST:
         case ICEWM_ACTION_ABOUT:
-            break;
+            //break;
         default:
             smActionListener->handleSMAction(message.data.l[1]);
             break;
