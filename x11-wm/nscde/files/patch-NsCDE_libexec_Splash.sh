--- NsCDE/libexec/Splash.sh.orig	2021-05-02 08:29:06 UTC
+++ NsCDE/libexec/Splash.sh
@@ -64,11 +64,11 @@ Begin
       Quit
    End
 
-   Do {Colorset 70 TiledPixmap \$[NSCDE_ROOT]/lib/progbits/$SplashBG}
+   Do {Colorset 70 TiledPixmap ${PREFIX}/lib/nscde/progbits/$SplashBG}
    Do {Test (!EnvMatch FVWM_IS_FVWM3 1) Schedule 120 All (NsCDE-Splash) Move screen g 50-50w 50-50w ewmhiwa}
    Do {Test (EnvMatch FVWM_IS_FVWM3 1) Schedule 120 All (NsCDE-Splash) Move screen p +0p +0p}
 
-   Set \$MainFontCmd = (GetOutput {\$NSCDE_ROOT/bin/getfont -v -t bold -s large} 1 -1)
+   Set \$MainFontCmd = (GetOutput {${PREFIX}/sbin/getfont -v -t bold -s large} 1 -1)
    Set \$MainFont = {Shadow=1 0 SE:} \$MainFontCmd
 
    ChangeFont 5 \$MainFont
