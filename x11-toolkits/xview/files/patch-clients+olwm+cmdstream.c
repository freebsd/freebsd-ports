--- ./clients/olwm/cmdstream.c.orig	Tue Jun 29 07:11:43 1993
+++ ./clients/olwm/cmdstream.c	Sat Apr  1 18:26:06 2000
@@ -51,10 +51,10 @@ static	CmdInfo		cmdInfo = {
  *      Local Forward Declarations
  * ---------------------------------------------------------------------*/
 
-Command		*MatchCommand();
-CmdAttr		*MatchAttr();
-int		EncodeAttrValue();
-int		DecodeAttrValue();
+static Command		*MatchCommand();
+static CmdAttr		*MatchAttr();
+static int		EncodeAttrValue();
+static int		DecodeAttrValue();
 
 /* ----------------------------------------------------------------------
  *      SetCmdStream
