Index: programs/Xserver/os/access.c
===================================================================
RCS file: /home/ncvs/xfree/xc/programs/Xserver/os/access.c,v
retrieving revision 3.43
retrieving revision 3.44
diff -u -u -r3.43 -r3.44
--- programs/Xserver/os/access.c	20 Apr 2003 18:35:12 -0000	3.43
+++ programs/Xserver/os/access.c	25 May 2003 10:38:47 -0000	3.44
@@ -745,6 +745,7 @@
 	if (ifr->ifa_addr.sa_family == AF_DECnet) 
 	    continue;
 #endif /* DNETCONN */
+	len = sizeof(*(ifr->ifa_addr));
 	family = ConvertAddr(ifr->ifa_addr, &len, (pointer *)&addr);
 	if (family == -1 || family == FamilyLocal) 
 	    continue;
