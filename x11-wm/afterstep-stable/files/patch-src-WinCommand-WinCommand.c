$FreeBSD$

--- src/WinCommand/WinCommand.c.orig	Sat Jun 24 22:08:22 2006
+++ src/WinCommand/WinCommand.c	Sat Jun 24 22:09:07 2006
@@ -307,12 +307,13 @@
 	ASBiDirElem *curr;
 	char *command;
 	action_t *a;
-	ASWinCommandState WinCommandState ; 
+	ASWinCommandState WinCommandState ;
+	ASBiDirList *operations;
 
 	InitMyApp (CLASS_WINCOMMAND, argc, argv, NULL, NULL, OPTION_SINGLE|OPTION_RESTART );
 	ConnectX( ASDefaultScr, 0 );
 
-	ASBiDirList *operations = create_asbidirlist( NULL );
+	operations = create_asbidirlist( NULL );
 	
 	/* Initialize State */
 	memset( &WinCommandState, 0x00, sizeof(WinCommandState));
