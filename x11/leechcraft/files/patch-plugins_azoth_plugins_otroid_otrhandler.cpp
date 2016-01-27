--- plugins/azoth/plugins/otroid/otrhandler.cpp.orig	2014-07-28 20:35:44.000000000 +0200
+++ plugins/azoth/plugins/otroid/otrhandler.cpp	2016-01-26 13:30:45.499740000 +0100
@@ -510,7 +510,7 @@ namespace OTRoid
 		auto list = proxy->GetReturnValue ().toList ();
 
 		const auto& actionsStruct = Entry2Action_.value (entry);
-		const auto actions
+		const auto actions =
 		{
 			actionsStruct.ToggleOtr_.get (),
 			actionsStruct.ToggleOtrCtx_.get (),
