*** src/actions.c.orig	Sun Nov  3 12:58:30 2002
--- src/actions.c	Sat Jul  6 17:31:27 2002
***************
*** 2078,2084 ****
    return NULL;
  }
  
! #if !defined(HAVE_SETENV) || !defined(setenv)
  /* For systems, such as Solaris, where setenv is not implemented
   * in libc */
  /* FIXME: overwrite has no effect in this implementation! */
--- 2078,2084 ----
    return NULL;
  }
  
! #if !defined(HAVE_SETENV) && !defined(setenv)
  /* For systems, such as Solaris, where setenv is not implemented
   * in libc */
  /* FIXME: overwrite has no effect in this implementation! */
