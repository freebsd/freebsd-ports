--- modules/FvwmProxy/FvwmProxy.c.orig	Fri Aug 12 08:25:45 2005
+++ modules/FvwmProxy/FvwmProxy.c	Wed Nov  9 07:29:08 2005
@@ -719,14 +719,15 @@
 {
 	Bool rc = False;
 	ProxyWindow *other=proxy->next;
+	int dx, dy;
 
 	for (other=proxy->next; other; other=other->next)
 	{
 		if(other->desk != deskNumber)
 			continue;
 
-		int dx=abs(proxy->proxyx-other->proxyx);
-		int dy=abs(proxy->proxyy-other->proxyy);
+		dx=abs(proxy->proxyx-other->proxyx);
+		dy=abs(proxy->proxyy-other->proxyy);
 		if (dx<(proxyWidth+proxySeparation) &&
 				dy<proxyHeight+proxySeparation )
 		{
