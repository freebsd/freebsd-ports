*** xb_check.c.orig	Mon May 12 17:55:59 1997
--- xb_check.c	Tue May 18 20:51:35 1999
***************
*** 145,151 ****
  }
  
  /* boolean that checks if a string is numeric */
! int isnumber(char *s)
  {
    if(atoi(s)==0 && *s!='0')
      return 0;
--- 145,151 ----
  }
  
  /* boolean that checks if a string is numeric */
! int isnumb(char *s)
  {
    if(atoi(s)==0 && *s!='0')
      return 0;
***************
*** 303,309 ****
      }
    }
  
!   while(gets(line)!=NULL)
    {
      if(line[0]=='!')
        continue;
--- 303,309 ----
      }
    }
  
!   while(fgets(line, LNLEN, stdin)!=NULL)
    {
      if(line[0]=='!')
        continue;
***************
*** 363,369 ****
              printf("Valid resource name with unknown program name:\n%s\n",line);
            if(val[0]=='\0')
              printf("No value in line containing valid resource name:\n%s\n",line);
! 	  if(!isnumber(val))
  	    printf("Value in line requiring a numerical value is not numerical:\n%s\n",line);
          }
          else
--- 363,369 ----
              printf("Valid resource name with unknown program name:\n%s\n",line);
            if(val[0]=='\0')
              printf("No value in line containing valid resource name:\n%s\n",line);
! 	  if(!isnumb(val))
  	    printf("Value in line requiring a numerical value is not numerical:\n%s\n",line);
          }
          else
***************
*** 373,379 ****
              printf("Valid resource class name with unknown program name:\n%s\n",line);
            if(val[0]=='\0')
              printf("No value in line containing valid resource class name:\n%s\n",line);
! 	  if(!isnumber(val))
  	    printf("Value in line requiring a numerical value is not numerical:\n%s\n",line);
          }
          break;
--- 373,379 ----
              printf("Valid resource class name with unknown program name:\n%s\n",line);
            if(val[0]=='\0')
              printf("No value in line containing valid resource class name:\n%s\n",line);
! 	  if(!isnumb(val))
  	    printf("Value in line requiring a numerical value is not numerical:\n%s\n",line);
          }
          break;
