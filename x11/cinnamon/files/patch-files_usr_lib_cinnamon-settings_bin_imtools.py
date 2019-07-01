From c843f3664064742e2672e0fea528571a882d84ad Mon Sep 17 00:00:00 2001
From: Eli Schwartz <eschwartz93@gmail.com>
Date: Fri, 5 Apr 2019 11:28:45 -0400
Subject: [PATCH] PIL: remove unnnecessary version check and code fork (#8496)

The Image.VERSION variable was deprecated some time ago and is now gone
entirely. But its only use was to determine whether we were using at
least the latest version of PIL, or any version of its fork, Pillow. And
PIL was last developed in 2009 and does not support python3 at all, so
we are guaranteed to be using Pillow.

Moreover, the check does not really matter, as Pillow is guaranteed to
load any image it opens, without the user doing so manually.

Fixes #8495

--- files/usr/lib/cinnamon-settings/bin/imtools.py.orig	2019-05-23 10:40:29 UTC
+++ files/usr/lib/cinnamon-settings/bin/imtools.py
@@ -618,32 +618,6 @@ def has_transparency(image):
     return (image.mode == 'P' and 'transparency' in image.info) or\
             has_alpha(image)
 
-
-if Image.VERSION == '1.1.7':
-
-    def split(image):
-        """Work around for bug in Pil 1.1.7
-
-        :param image: input image
-        :type image: PIL image object
-        :returns: the different color bands of the image (eg R, G, B)
-        :rtype: tuple
-        """
-        image.load()
-        return image.split()
-else:
-
-    def split(image):
-        """Work around for bug in Pil 1.1.7
-
-        :param image: input image
-        :type image: PIL image object
-        :returns: the different color bands of the image (eg R, G, B)
-        :rtype: tuple
-        """
-        return image.split()
-
-
 def get_alpha(image):
     """Gets the image alpha band. Can handles P mode images with transpareny.
     Returns a band with all values set to 255 if no alpha band exists.
@@ -654,7 +628,7 @@ def get_alpha(image):
     :rtype: single band image object
     """
     if has_alpha(image):
-        return split(image)[-1]
+        return image.split()[-1]
     if image.mode == 'P' and 'transparency' in image.info:
         return image.convert('RGBA').split()[-1]
     # No alpha layer, create one.
