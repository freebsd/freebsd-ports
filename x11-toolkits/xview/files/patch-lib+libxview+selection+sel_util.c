--- ./lib/libxview/selection/sel_util.c.orig	Tue Jun 29 07:16:03 1993
+++ ./lib/libxview/selection/sel_util.c	Sat Apr  1 18:25:28 2000
@@ -23,6 +23,7 @@ static void tvdiff();
 static void FreeMultiProp();
 static int	SelMatchReply();
 static Sel_req_tbl *SelMatchReqTbl();
+static int SelFindReply();
 
 Pkg_private struct timeval *
 xv_sel_cvt_xtime_to_timeval( XTime )
@@ -601,7 +602,7 @@ Sel_reply_info  *reply;
 	reqTbl->reply = reply;
 	reqTbl->next = NULL;
 	(void)XSaveContext( dpy, DefaultRootWindow(dpy),replyCtx,
-			   (caddr_t *)reqTbl);
+			   (XPointer)reqTbl);
 	return reqTbl;
     }
     return (Sel_req_tbl *) xv_sel_add_new_req( reqTbl, reply );
