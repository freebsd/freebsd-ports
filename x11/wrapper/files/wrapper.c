/*
 * X server wrapper.
 *
 * This wrapper makes some sanity checks on the command line arguments
 * and environment variables when run with euid == 0 && euid != uid.
 * If the checks fail, the wrapper exits with a message.
 * If they succeed, it exec's the Xserver.
 */

/*
 * Copyright (c) 1998 by The XFree86 Project, Inc.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE XFREE86 PROJECT BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 * OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of the XFree86 Project
 * shall not be used in advertising or otherwise to promote the sale,
 * use or other dealings in this Software without prior written
 * authorization from the XFree86 Project.
 */

/* $XFree86: xc/programs/Xserver/os/wrapper.c,v 1.1.2.9 1999/07/29 09:23:02 hohndel Exp $ */

/* This is normally set in the Imakefile */
#ifndef XSERVER_PATH
#define XSERVER_PATH	"/usr/X11R6/bin/XFree86"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#ifdef USE_PAM
#include <security/pam_appl.h>
#include <security/pam_misc.h>
#include <pwd.h>
#endif /* USE_PAM */

/* Neither of these should be required for XFree86 3.3.2 */
#ifndef REJECT_CONFIG
#define REJECT_CONFIG 0
#endif
#ifndef REJECT_XKBDIR
#define REJECT_XKBDIR 0
#endif

/* Consider LD* variables insecure ? */
#ifndef REMOVE_ENV_LD
#define REMOVE_ENV_LD 1
#endif

/* Remove long environment variables? */
#ifndef REMOVE_LONG_ENV
#define REMOVE_LONG_ENV 1
#endif

/* Check args and env only if running setuid (euid == 0 && euid != uid) ? */
#ifndef CHECK_EUID
#define CHECK_EUID 1
#endif

/*
 * Maybe the locale can be faked to make isprint(3) report that everything
 * is printable?  Avoid it by default.
 */
#ifndef USE_ISPRINT
#define USE_ISPRINT 0
#endif

#define MAX_ARG_LENGTH		128
#define MAX_ENV_LENGTH		256
#define MAX_ENV_PATH_LENGTH	2048

#if USE_ISPRINT
#include <ctype.h>
#define checkPrintable(c) isprint(c)
#else
#define checkPrintable(c) (((c) & 0x7f) >= 0x20 && ((c) & 0x7f) != 0x7f)
#endif

enum BadCode {
    NotBad = 0,
    UnsafeArg,
    ArgTooLong,
    UnprintableArg,
    EnvTooLong,
    InternalError
#ifdef USE_PAM
    ,PamFailed,
    PamAuthFailed
#endif /* USE_PAM */
};

#define ARGMSG \
    "\nIf the arguments used are valid, and have been rejected incorrectly\n" \
      "please send details of the arguments and why they are valid to\n" \
      "XFree86@XFree86.org.  In the meantime, you can start the Xserver as\n" \
      "the \"super user\" (root).\n"   

#define ENVMSG \
    "\nIf the environment is valid, and have been rejected incorrectly\n" \
      "please send details of the environment and why it is valid to\n" \
      "XFree86@XFree86.org.  In the meantime, you can start the Xserver as\n" \
      "the \"super user\" (root).\n"

#ifdef USE_PAM
static struct pam_conv conv = {
    misc_conv,
    NULL
};
#endif /* USE_PAM */


int
main(int argc, char **argv, char **envp)
{
    enum BadCode bad = NotBad;
    int i, j;
    char *a, *e;
#ifdef USE_PAM
    pam_handle_t *pamh = NULL;
    struct passwd *pw;
    int retval;

    pw = getpwuid(getuid());
    if (pw == NULL) {
	bad = InternalError;
    }

    if (!bad) {
	retval = pam_start("xserver", pw->pw_name, &conv, &pamh);
	if (retval != PAM_SUCCESS)
	    bad = PamFailed;
    }

    if (!bad) {
	retval = pam_authenticate(pamh, 0);
	if (retval != PAM_SUCCESS) {
	    pam_end(pamh, retval);
	    bad = PamAuthFailed;
	}
    }

    if (!bad) {
	retval = pam_acct_mgmt(pamh, 0);
	if (retval != PAM_SUCCESS) {
	    pam_end(pamh, retval);
	    bad = PamAuthFailed;
	}
    }

    /* this is not a session, so do not do session management */

    if (!bad) pam_end(pamh, PAM_SUCCESS);
#endif /* USE_PAM */

#if CHECK_EUID
    if (!bad && geteuid() == 0 && getuid() != geteuid()) {
#else
    if (!bad) {
#endif
	/* Check each argv[] */
	for (i = 1; i < argc; i++) {

	    /* Check for known bad arguments */
#if REJECT_CONFIG
	    if (strcmp(argv[i], "-config") == 0) {
		bad = UnsafeArg;
		break;
	    }
#endif
#if REJECT_XKBDIR
	    if (strcmp(argv[i], "-xkbdir") == 0) {
		bad = UnsafeArg;
		break;
	    }
#endif
	    if (strlen(argv[i]) > MAX_ARG_LENGTH) {
		bad = ArgTooLong;
		break;
	    }
	    a = argv[i];
	    while (*a) {
		if (checkPrintable(*a) == 0) {
		    bad = UnprintableArg;
		    break;
		}
		a++;
	    }
	    if (bad)
		break;
	}
	/* Check each envp[] */
	if (!bad)
	    for (i = 0; envp[i]; i++) {

		/* Check for bad environment variables and values */
#if REMOVE_ENV_LD
		while (envp[i] && (strncmp(envp[i], "LD", 2) == 0)) {
		    for (j = i; envp[j]; j++) {
			envp[j] = envp[j+1];
		    }
		}
#endif   
		if (envp[i] && (strlen(envp[i]) > MAX_ENV_LENGTH)) {
#if REMOVE_LONG_ENV
		    for (j = i; envp[j]; j++) {
			envp[j] = envp[j+1];
		    }
		    i--;
#else
		    char *eq;
		    int len;

		    eq = strchr(envp[i], '=');
		    if (!eq)
			continue;
		    len = eq - envp[i];
		    e = malloc(len + 1);
		    if (!e) {
			bad = InternalError;
			break;
		    }
		    strncpy(e, envp[i], len);
		    e[len] = 0;
		    if (len >= 4 &&
			(strcmp(e + len - 4, "PATH") == 0 ||
			 strcmp(e, "TERMCAP") == 0)) {
			if (strlen(envp[i]) > MAX_ENV_PATH_LENGTH) {
			    bad = EnvTooLong;
			    break;
			} else {
			    free(e);
			}
		    } else {
			bad = EnvTooLong;
			break;
		    }
#endif
		}
	    }
    }
    switch (bad) {
    case NotBad:
	argv[0] = XSERVER_PATH;
	execve(XSERVER_PATH, argv, envp);
	fprintf(stderr, "execve failed for %s (errno %d)\n", XSERVER_PATH,
		errno);
	break;
    case UnsafeArg:
	fprintf(stderr, "Command line argument number %d is unsafe\n", i);
	fprintf(stderr, ARGMSG);
	break;
    case ArgTooLong:
	fprintf(stderr, "Command line argument number %d is too long\n", i);
	fprintf(stderr, ARGMSG);
	break;
    case UnprintableArg:
	fprintf(stderr, "Command line argument number %d contains unprintable"
		" characters\n", i);
	fprintf(stderr, ARGMSG);
	break;
    case EnvTooLong:
	fprintf(stderr, "Environment variable `%s' is too long\n", e);
	fprintf(stderr, ENVMSG);
	break;
    case InternalError:
	fprintf(stderr, "Internal Error\n");
	break;
#ifdef USE_PAM
    case PamFailed:
	fprintf(stderr, "Authentication System Failure, "
			"missing or mangled PAM configuration file or module?\n");
	break;
    case PamAuthFailed:
	fprintf(stderr, "Authentication failed - cannot start X server.\nPerhaps you do not have console ownership?");
	break;
#endif
    default:
	fprintf(stderr, "Unknown error\n");
	fprintf(stderr, ARGMSG);
	fprintf(stderr, ENVMSG);
	break;
    }
    exit(1);
}
