*** filer.c.orig	Thu May 26 21:59:10 1994
--- filer.c	Tue Sep  3 15:01:15 1996
***************
*** 85,91 ****
  {
  	int i ;
  	int nchars ;
! 	char * filename[138] ;
  	int bytesperrow ;
          unsigned char * vidmem ;
  	int vidwidth ;
--- 85,91 ----
  {
  	int i ;
  	int nchars ;
! 	char filename[138] ;
  	int bytesperrow ;
          unsigned char * vidmem ;
  	int vidwidth ;
***************
*** 187,193 ****
      fprintf(stderr,"\n");
      fprintf(stderr, msg, p1, p2, p3, p4);
      fprintf(stderr,"\n");
!     fclose(pF);
      return -1 ;
  }
  
--- 187,196 ----
      fprintf(stderr,"\n");
      fprintf(stderr, msg, p1, p2, p3, p4);
      fprintf(stderr,"\n");
!     if (pF != NULL) {
! 	fclose(pF);
! 	pF = NULL;
!     }
      return -1 ;
  }
  
***************
*** 300,306 ****
  
      if (!Extension(filename,".bdf")) strcat(filename,".bdf");
  
!     if ((pF = fopen( filename, "r")) == NULL) return fatal("Can't open file");
  
      getline(linebuf);
      if ((sscanf(linebuf, "STARTFONT %s", namebuf) != 1) ||
--- 303,309 ----
  
      if (!Extension(filename,".bdf")) strcat(filename,".bdf");
  
!     if ((pF = fopen( filename, "r")) == NULL) return fatal("Can't open file %s", filename);
  
      getline(linebuf);
      if ((sscanf(linebuf, "STARTFONT %s", namebuf) != 1) ||
