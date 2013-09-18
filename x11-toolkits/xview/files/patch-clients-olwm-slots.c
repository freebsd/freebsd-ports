--- clients/olwm/slots.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/slots.c	2013-09-17 22:57:38.862493883 -0700
@@ -449,7 +449,7 @@
 
 	if (winicon->iconslot == NULL)
 	{
-		return;
+		return 0;
 	}
 
 	incrRegion(iconGrid,winicon->iconslot,-1);
@@ -539,7 +539,7 @@
 		for (ima = 0; ima<iconGrid->maslots; ima++)
 		    for (imi = 0; imi<iconGrid->mislots; imi++)
 			OCCUPANCY(iconGrid,ima,imi)=0;
-		return;
+		return 0;
 	}
 
 	/* partition existing icons */
