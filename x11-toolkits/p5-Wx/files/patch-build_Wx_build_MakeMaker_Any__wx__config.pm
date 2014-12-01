--- build/Wx/build/MakeMaker/Any_wx_config.pm.orig	2014-03-08 13:01:15 UTC
+++ build/Wx/build/MakeMaker/Any_wx_config.pm
@@ -39,15 +39,6 @@ sub get_flags {
   return %config;
 }
 
-sub const_config {
-    my $text = shift->SUPER::const_config( @_ );
-
-    $text =~ s{^(LD(?:DL)?FLAGS\s*=.*?)-L/usr/local/lib64/?}{$1}mg;
-    $text =~ s{^(LD(?:DL)?FLAGS\s*=.*?)-L/usr/local/lib/?}{$1}mg;
-
-    return $text;
-}
-
 1;
 
 # local variables:
