--- libxfdashboard/applications-menu-model.c.orig	2018-04-25 20:40:40 UTC
+++ libxfdashboard/applications-menu-model.c
@@ -440,7 +440,7 @@ static void _xfdashboard_applications_menu_model_fill_
 
 			item=_xfdashboard_applications_menu_model_item_new();
 			item->sequenceID=inFillData->sequenceID;
-			if(inMenu) item->menuElement=g_object_ref(inMenu);
+			if(inMenu) item->menuElement=GARCON_MENU_ELEMENT(inMenu);
 			if(inParentMenu) item->parentMenu=g_object_ref(inParentMenu);
 			if(section) item->section=g_object_ref(section);
 			if(title) item->title=g_strdup(title);
