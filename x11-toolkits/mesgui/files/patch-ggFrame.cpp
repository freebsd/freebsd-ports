--- src/ggFrame.cpp.pre_tr.orig	2007-08-12 19:28:07.000000000 +0200
+++ src/ggFrame.cpp	2007-08-12 19:28:25.000000000 +0200
@@ -450,7 +450,7 @@
 
 void ggFrame::AddCloseButton()
 {
-	ggButton *button = new ggButton("",OnClose,(int)this,0,0,0,0);
+	ggButton *button = new ggButton("",OnClose,(intptr_t)this,0,0,0,0);
 	button->flags |= GGFLAG_ICON;
 	button->icon = GGICON_CLOSE;
 	button->SetPos(xsize-COL_HEIGHT+3,-COL_HEIGHT+3,COL_HEIGHT-6,COL_HEIGHT-6);
