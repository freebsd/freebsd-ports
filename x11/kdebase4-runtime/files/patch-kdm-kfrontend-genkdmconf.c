--- kdm/kfrontend/genkdmconf.c.orig	Wed Feb 23 12:26:01 2005
+++ kdm/kfrontend/genkdmconf.c	Sat Mar 19 16:43:49 2005
@@ -562,7 +562,7 @@
 "# by Xsetup usually.\n"
 "# This is not required if you use PAM with the pam_console module.\n"
 "#\n"
-"#chown $USER /dev/console\n"
+"chown $USER /dev/console\n"
 "\n"
 #ifdef _AIX
 "# We create a pseudodevice for finger.  (host:0 becomes xdm/host_0)\n"
@@ -591,8 +591,8 @@
 "# Reassign ownership of the console to root, this should disallow\n"
 "# assignment of console output to any random users's xterm. See Xstartup.\n"
 "#\n"
-"#chown root /dev/console\n"
-"#chmod 622 /dev/console\n"
+"chown root /dev/console\n"
+/* "#chmod 622 /dev/console\n" */
 "\n"
 #ifdef _AIX
 "#devname=`echo $DISPLAY | cut -c1-8`\n"
@@ -609,6 +609,8 @@
 "#! /bin/sh\n"
 "# Xsession - run as user\n"
 "\n"
+"session=$1\n"
+"\n"
 "# Note that the respective logout scripts are not sourced.\n"
 "case $SHELL in\n"
 "  */bash)\n"
@@ -637,7 +639,9 @@
 "  */csh|*/tcsh)\n"
 "    # [t]cshrc is always sourced automatically.\n"
 "    # Note that sourcing csh.login after .cshrc is non-standard.\n"
-"    eval `$SHELL -c 'if (-f /etc/csh.login) source /etc/csh.login > /dev/null; if (-f ~/.login) source ~/.login > /dev/null; /bin/sh -c export'`\n"
+"    set -a\n"
+"    eval `$SHELL -c 'if (-f /etc/csh.login) source /etc/csh.login >& /dev/null; if (-f ~/.login) source ~/.login >& /dev/null; printenv | egrep -v \"^(TERM|SHLVL)=\"'`\n"
+"    set +a\n"
 "    ;;\n"
 "  *) # Plain sh, ksh, and anything we don't know.\n"
 "    [ -f /etc/profile ] && . /etc/profile\n"
@@ -648,7 +652,7 @@
 "[ -f /etc/xprofile ] && . /etc/xprofile\n"
 "[ -f $HOME/.xprofile ] && . $HOME/.xprofile\n"
 "\n"
-"case $1 in\n"
+"case $session in\n"
 "  \"\")\n"
 "    exec xmessage -center -buttons OK:0 -default OK \"Sorry, $DESKTOP_SESSION is no valid session.\"\n"
 "    ;;\n"
@@ -662,10 +666,10 @@
 "    exec " KDE_BINDIR "/startkde\n"
 "    ;;\n"
 "  *)\n"
-"    eval exec \"$1\"\n"
+"    eval exec \"$session\"\n"
 "    ;;\n"
 "esac\n"
-"exec xmessage -center -buttons OK:0 -default OK \"Sorry, cannot execute $1. Check $DESKTOP_SESSION.desktop.\"\n";
+"exec xmessage -center -buttons OK:0 -default OK \"Sorry, cannot execute $session. Check $DESKTOP_SESSION.desktop.\"\n";
 
 static const char def_background[] =
 "[Desktop0]\n"
@@ -817,7 +821,7 @@
  * XXX this stuff is highly borked. it does not handle collisions at all.
  */
 static int
-copyfile( Entry *ce, const char *tname, int mode, int (*proc)( File *, char **, int * ) )
+copyfile( Entry *ce, const char *tname, int mode, int (*proc)( File * ) )
 {
 	const char *tptr;
 	char *nname;
@@ -840,12 +844,7 @@
 		fprintf( stderr, "Warning: cannot copy file %s\n", ce->value );
 		rt = 0;
 	} else {
-		char *nbuf;
-		int nlen;
-
-		if (!proc || !proc( &file, &nbuf, &nlen ) ||
-		    (nlen == file.eof - file.buf && !memcmp( nbuf, file.buf, nlen )))
-		{
+		if (!proc || !proc( &file )) {
 			if (!use_destdir && !strcmp( ce->value, nname ))
 				linkedFile( nname );
 			else {
@@ -855,7 +854,7 @@
 				copiedFile( ce->value );
 			}
 		} else {
-			WriteOut( nname, mode, 0, nbuf, nlen );
+			WriteOut( nname, mode, 0, file.buf, file.eof - file.buf );
 			editedFile( ce->value );
 		}
 		if (strcmp( ce->value, nname ) && inNewDir( ce->value ) && !use_destdir)
@@ -1378,7 +1377,7 @@
 
 /*
 static int
-edit_resources(File *file, char **nbuf, int *nlen)
+edit_resources( File *file )
 {
 	// XXX remove any login*, chooser*, ... resources
 	return 0;
@@ -1415,15 +1414,14 @@
 				paap = pap += 2;
 				while (!isspace( *pap ))
 					pap++;
-				for (;;) {
-					if (*pp++ != '/')
-						goto no;
-					for (bpp = pp; *pp != '/'; pp++)
-						if (isspace( *pp ))
+				if (*pp != '/')
+					break;
+				for (;;)
+					for (bpp = ++pp; *pp != '/'; pp++)
+						if (!*pp || isspace( *pp ))
 							goto wbrk;
-				}
 			  wbrk:
-				if (memcmp( bpp, paap, pap - paap ))
+				if ((pp - bpp != pap - paap) || memcmp( bpp, paap, pap - paap ))
 					break;
 			} else if (*pap == '\t') {
 				pap++;
@@ -1472,24 +1470,25 @@
 static int mod_usebg;
 
 static int
-edit_setup( File *file, char **nbuf ATTR_UNUSED, int *nlen ATTR_UNUSED )
+edit_setup( File *file )
 {
-	putval( "UseBackground",
-	        (delstr( file, "\n"
-	                 "(\n"
-	                 "  PIDFILE=/var/run/kdmdesktop-$DISPLAY.pid\n"
-	                 "  */kdmdesktop\t&\n"
-	                 "  echo $! >$PIDFILE\n"
-	                 "  wait $!\n"
-	                 "  rm $PIDFILE\n"
-	                 ")\t&\n" ) ||
-	         delstr( file, "\n"
-	                 "*/kdmdesktop\t&\n" ) ||
-	         delstr( file, "\n"
-	                 "kdmdesktop\t&\n" ) ||
-	         delstr( file, "\n"
-	                 "kdmdesktop\n" )) ? "true" : "false" );
-	return 0;
+	int chg =
+		delstr( file, "\n"
+		        "(\n"
+		        "  PIDFILE=/var/run/kdmdesktop-$DISPLAY.pid\n"
+		        "  */kdmdesktop\t&\n"
+		        "  echo $! >$PIDFILE\n"
+		        "  wait $!\n"
+		        "  rm $PIDFILE\n"
+		        ")\t&\n" ) |
+		delstr( file, "\n"
+		        "*/kdmdesktop\t&\n" ) |
+		delstr( file, "\n"
+		        "kdmdesktop\t&\n" ) |
+		delstr( file, "\n"
+		        "kdmdesktop\n" );
+	putval( "UseBackground", chg ? "true" : "false" );
+	return chg;
 }
 
 static void
@@ -1515,19 +1514,22 @@
 }
 
 static int
-edit_startup( File *file, char **nbuf ATTR_UNUSED, int *nlen ATTR_UNUSED )
+edit_startup( File *file )
 {
+	int chg1 = 0, chg2 = 0;
+
 	if (mod_usebg &&
-	    !delstr( file, "\n"
+	    (delstr( file, "\n"
 	             "PIDFILE=/var/run/kdmdesktop-$DISPLAY.pid\n"
 	             "if [[] -f $PIDFILE ] ; then\n"
 	             "	   kill `cat $PIDFILE`\n"
-	             "fi\n" ))
-		delstr( file, "\n"
-		        "PIDFILE=/var/run/kdmdesktop-$DISPLAY.pid\n"
-		        "test -f $PIDFILE && kill `cat $PIDFILE`\n" );
-	if (oldver < 0x0203)
-		putval( "UseSessReg", (
+	             "fi\n" ) ||
+	     delstr( file, "\n"
+	             "PIDFILE=/var/run/kdmdesktop-$DISPLAY.pid\n"
+	             "test -f $PIDFILE && kill `cat $PIDFILE`\n" )))
+		chg1 = 1;
+	if (oldver < 0x0203) {
+		chg2 = 
 #ifdef _AIX
 			delstr( file, "\n"
 "# We create a pseudodevice for finger.  (host:0 becomes [kx]dm/host_0)\n" );
@@ -1552,11 +1554,11 @@
 "  else\n"
 "    exec /usr/lib/X11/xdm/sessreg -a -l [kx]dm/$devname -h $hostname $USER\n"
 "  fi\n"
-"fi\n") ||
+"fi\n") |
 #else
 # ifdef BSD
 			delstr( file, "\n"
-"exec sessreg -a -l $DISPLAY -x */Xservers -u " _PATH_UTMP " $USER\n" ) ||
+"exec sessreg -a -l $DISPLAY -x */Xservers -u " _PATH_UTMP " $USER\n" ) |
 # endif
 #endif /* _AIX */
 			delstr( file, "\n"
@@ -1564,11 +1566,12 @@
 #ifdef BSD
 " -x */Xservers"
 #endif
-" $USER\n" ) ||
+" $USER\n" ) |
 			delstr( file, "\n"
-"exec sessreg -a -l $DISPLAY -u /var/run/utmp -x */Xservers $USER\n" )
-		 ) ? "true" : "false");
-	return 0;
+"exec sessreg -a -l $DISPLAY -u /var/run/utmp -x */Xservers $USER\n" );
+		putval( "UseSessReg", chg2 ? "true" : "false");
+	}
+	return chg1 | chg2;
 }
 
 static void
@@ -1592,29 +1595,29 @@
 }
 
 static int
-edit_reset( File *file, char **nbuf ATTR_UNUSED, int *nlen ATTR_UNUSED )
+edit_reset( File *file )
 {
+	return
 #ifdef _AIX
-	delstr( file, "\n"
+		delstr( file, "\n"
 "if [[] -f /usr/lib/X11/xdm/sessreg ]; then\n"
 "  devname=`echo $DISPLAY | /usr/bin/sed -e 's/[[]:\\.]/_/g' | /usr/bin/cut -c1-8`\n"
 "  exec /usr/lib/X11/xdm/sessreg -d -l [kx]dm/$devname $USER\n"
-"fi\n" );
+"fi\n" ) |
 #else
 # ifdef BSD
-	delstr( file, "\n"
-"exec sessreg -d -l $DISPLAY -x */Xservers -u " _PATH_UTMP " $USER\n" );
+		delstr( file, "\n"
+"exec sessreg -d -l $DISPLAY -x */Xservers -u " _PATH_UTMP " $USER\n" ) |
 # endif
 #endif /* _AIX */
-	delstr( file, "\n"
+		delstr( file, "\n"
 "exec sessreg -d -l $DISPLAY"
 # ifdef BSD
 " -x */Xservers"
 # endif
-" $USER\n" );
-	delstr( file, "\n"
+" $USER\n" ) |
+		delstr( file, "\n"
 "exec sessreg -d -l $DISPLAY -u /var/run/utmp -x */Xservers $USER\n" );
-	return 0;
 }
 
 static void
