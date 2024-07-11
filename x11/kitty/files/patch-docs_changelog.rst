--- docs/changelog.rst.orig	1979-11-29 23:00:00 UTC
+++ docs/changelog.rst
@@ -3391,7 +3391,7 @@ - A :doc:`new kitten <kittens/panel>` to create dock p
 - A :doc:`new kitten <kittens/panel>` to create dock panels on X11 desktops
   showing the output from arbitrary terminal programs.
 
-- Reduce data sent to the GPU per render by 30% (:commit:`8dea5b3`)
+- Reduce data sent to the GPU per render by 30% (:commit:`8dea5b3e3ec1db8597f3a3649b5cefd52f41e409`)
 
 - Implement changing the font size for individual top level (OS) windows
   (:iss:`408`)
@@ -3506,7 +3506,7 @@ - Implement support for the SGR *faint* escape code to
 - Implement support for the SGR *faint* escape code to make text blend
   into the background (:iss:`446`).
 
-- Make the hints kitten a little smarter (:commit:`ad1109b`)
+- Make the hints kitten a little smarter (:commit:`ad1109b6fe0a6802ca4f77182a7a0b36086b3e9f`)
   so that URLs that stretch over multiple lines are detected. Also improve
   detection of surrounding brackets/quotes.
 
@@ -3518,7 +3518,7 @@ - Expand environment variables in config file include 
 
 - Expand environment variables in config file include directives
 
-- Allow programs running in kitty to read/write from the clipboard (:commit:`889ca77`).
+- Allow programs running in kitty to read/write from the clipboard (:commit:`889ca7791244253cb08fbc3eca8883a87fb943a7`).
   By default only writing is allowed. This feature is supported in many
   terminals, search for `OSC 52 clipboard` to find out more about using it.
 
