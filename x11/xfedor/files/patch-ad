*** couchex.c.orig	Thu May 26 21:59:03 1994
--- couchex.c	Tue Sep  3 02:09:18 1996
***************
*** 366,377 ****
  {
  	XEvent rep ;
  	static int ZoneCour = 0 ;
! 	int i, keysym ;
  	char s[1] ;
  
  	do {
  	   XNextEvent(Dpl,&rep) ;
!            if (rep.type == KeyPress) XLookupString(&rep,s,1,&keysym,NULL);
  	} while ( ((rep.type != Expose) || (rep.xexpose.count != 0)) &&
  		  ((rep.type != KeyPress) || (IsModifierKey(keysym))) &&
  		  (rep.type != ButtonPress) &&
--- 366,378 ----
  {
  	XEvent rep ;
  	static int ZoneCour = 0 ;
! 	int i ;
! 	KeySym keysym ;
  	char s[1] ;
  
  	do {
  	   XNextEvent(Dpl,&rep) ;
! 	   if (rep.type == KeyPress) XLookupString(&rep.xkey,s,1,&keysym,NULL);
  	} while ( ((rep.type != Expose) || (rep.xexpose.count != 0)) &&
  		  ((rep.type != KeyPress) || (IsModifierKey(keysym))) &&
  		  (rep.type != ButtonPress) &&
***************
*** 788,798 ****
          int wd ;
  { 
          int px, py ;
! 	long bidon ;
  	XWindowAttributes watt ;
  
  	XGetWindowAttributes(Dpl,wd,&watt);
! 	XQueryPointer(Dpl,root,&bidon,&bidon,&px,&py,&bidon,&bidon,&bidon);
  	
  	if ((px + watt.width/2) > DisplayWidth(Dpl,screen))
  	  px = DisplayWidth(Dpl,screen) - watt.width/2 ;
--- 789,801 ----
          int wd ;
  { 
          int px, py ;
! 	Window bidon ;
! 	int fake;
! 	unsigned int mfake;
  	XWindowAttributes watt ;
  
  	XGetWindowAttributes(Dpl,wd,&watt);
! 	XQueryPointer(Dpl,root,&bidon,&bidon,&px,&py,&fake,&fake,&mfake);
  	
  	if ((px + watt.width/2) > DisplayWidth(Dpl,screen))
  	  px = DisplayWidth(Dpl,screen) - watt.width/2 ;
