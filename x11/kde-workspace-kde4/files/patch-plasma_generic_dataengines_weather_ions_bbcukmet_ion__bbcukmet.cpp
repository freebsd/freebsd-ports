--- plasma/generic/dataengines/weather/ions/bbcukmet/ion_bbcukmet.cpp.orig	2018-08-30 10:05:25 UTC
+++ plasma/generic/dataengines/weather/ions/bbcukmet/ion_bbcukmet.cpp
@@ -312,11 +312,11 @@ void UKMETIon::readSearchHTMLData(const 
 
     while (!stream.atEnd()) {
        line = stream.readLine();
-       if (line.contains("<p class=\"response\">") > 0) {
+       if (line.contains("<p class=\"response\">")) {
            flag = 1;
        }
 
-       if (line.contains("There are no forecasts matching") > 0) {
+       if (line.contains("There are no forecasts matching")) {
            break;
        }
 
@@ -342,7 +342,7 @@ void UKMETIon::readSearchHTMLData(const 
             }
        }
 
-       if (line.contains("<div class=\"line\">") > 0) {
+       if (line.contains("<div class=\"line\">")) {
            flag = 0;
        }
     }
