--- ./lib/libxview/selection/sel_req.c.orig	Sun Jun 26 03:05:21 1994
+++ ./lib/libxview/selection/sel_req.c	Sat Apr  1 18:25:28 2000
@@ -55,7 +55,10 @@ static int ProcessMultiple();
 static int GetSelection();
 static int ProcessReply();
 static Requestor *SelGetReq();
-
+static int XvGetRequestedValue();
+static int ProcessNonBlkIncr();
+static int ProcessReq();
+static int OldPkgIsOwner();
 
 /*ARGSUSED*/
 Pkg_private int
@@ -1226,7 +1229,7 @@ Selection_requestor  sel;
 }
 
 
-static XID 
+Pkg_private XID 
 SelGetOwnerXID( selReq )
 Sel_req_info  *selReq;
 {
