--- slots.c.orig	2013-09-17 21:38:07.382240689 -0700
+++ slots.c	2013-09-17 21:50:50.762215147 -0700
@@ -542,7 +542,7 @@
 
 	if (winicon->iconslot == NULL)
 	{
-		return;
+		return 0;
 	}
 
 	incrRegion(iconGrid,winicon->iconslot,-1);
@@ -627,7 +627,7 @@
 		for (ima = 0; ima<iconGrid->maslots; ima++)
 		    for (imi = 0; imi<iconGrid->mislots; imi++)
 			OCCUPANCY(iconGrid,ima,imi)=0;
-		return;
+		return 0;
 	}
 
 	/* partition existing icons */
