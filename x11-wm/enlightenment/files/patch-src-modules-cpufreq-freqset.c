--- src/modules/cpufreq/freqset.c	2015-01-24 11:58:59.000000000 +0200
+++ src/modules/cpufreq/freqset.c	2015-01-24 11:58:51.000000000 +0200
@@ -59,7 +59,7 @@ 
      {
         int new_frequency = atoi(argv[2]);
         size_t len = sizeof(new_frequency);
-        if (sysctlbyname("dev.cpu.0.freq", NULL, 0, &new_frequency, &len) == -1)
+        if (sysctlbyname("dev.cpu.0.freq", NULL, 0, &new_frequency, len) == -1)
           {
              fprintf(stderr, "Unable to open frequency interface for writing.\n");
              return 1;
