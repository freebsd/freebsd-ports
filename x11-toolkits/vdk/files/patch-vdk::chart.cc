--- vdk/chart.cc.orig	Wed May 22 17:26:12 2002
+++ vdk/chart.cc	Thu Aug  5 19:16:35 2004
@@ -45,7 +45,10 @@
   size = Usize;
   printf("\nsize:%d,%d",size.x,size.y);
   fflush(stdout);
-  axis = ChartAxis(this,size.X(),size.Y());
+  // patch Bug#262091
+  // axis = ChartAxis(this,size.X(),size.Y());
+  ChartAxis axis_tmp( this, size.X(), size.Y() );
+  axis = axis_tmp;
   axis.Draw();
   DrawTitle();
   DrawChart();
@@ -115,7 +118,10 @@
 void VDKChart::SetChartBorder(int b)
 {
 size = Usize;
-axis = ChartAxis(this,size.X(),size.Y());
+// patch Bug#262091
+// axis = ChartAxis(this,size.X(),size.Y());
+ChartAxis axis_tmp(this,size.X(),size.Y());
+axis = axis_tmp;
 DrawChart();
 }
 /*
@@ -415,10 +421,18 @@
 ChartAxis::ChartAxis(VDKChart* owner,int w, int h):
   owner(owner)
 {
+// patch Bug#262091
+/*
   domain = VDKRect(owner->ChartBorder,
 		   h-owner->ChartBorder,
 		   w-owner->ChartBorder*2,
 		   h-owner->ChartBorder*2);
+*/
+VDKRect r(owner->ChartBorder,
+ 		   h-owner->ChartBorder,
+ 		   w-owner->ChartBorder*2,
+ 		   h-owner->ChartBorder*2);
+domain = r;
 }
 /*
 copy-initializer
