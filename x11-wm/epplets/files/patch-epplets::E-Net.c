--- epplets/E-Net.c.orig	Wed Aug  1 19:46:50 2001
+++ epplets/E-Net.c	Wed Aug  1 19:52:34 2001
@@ -14,6 +14,7 @@
 
 double              upstream_max = 1540000;
 double              downstream_max = 1540000;
+char 				*netdev;
 int                 up_val = 0;
 int                 down_val = 0;
 double              up_last = 0;
@@ -34,7 +35,7 @@
    double              val = -1.0, val2 = -1.0, dval, dval2;
    unsigned char       invalid;
 
-   invalid = net_get_bytes_inout("eth0", &val, &val2);
+   invalid = net_get_bytes_inout(netdev, &val, &val2);
    if (invalid)
      {
 	char                err[255];
@@ -74,6 +75,7 @@
    Epplet_modify_config("upstream_max", s);
    Esnprintf(s, sizeof(s), "%f", downstream_max);
    Epplet_modify_config("downstream_max", s);
+   Epplet_modify_config("device", netdev);
    Epplet_save_config();
 }
 
@@ -87,6 +89,8 @@
 
    s = Epplet_query_config_def("downstream_max", "1540000");
    downstream_max = (double)atof(s);
+
+   netdev = Epplet_query_config_def("device", "eth0");
 }
 
 static void
