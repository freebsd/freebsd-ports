# New ports collection makefile for:    XFree86
# Version required:     3.1.1
# Date created:         5 January 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.5 1995/04/12 20:26:23 asami Exp $
#

#######################################################################
#                                                                     #
#                        Configurable Section                         #
#                                                                     #
#######################################################################
#
# uncomment one of the 3 lines below!
#(X-Consortium CDROM, O'Reilly 'X-Companion' CDROM, or X by FTP (_*BIG*_)
#X11_ON_X_CDROM	=	yes
#X11_ON_OR_CDROM	=	yes
#X11_VIA_FTP	=	yes

#if you are compiling from a cdrom, set the directory where the
# the patch files are
X11FIXES = /usr/ports/distfiles/xc

#define this if you are short of space - save ~28 Mbytes
#REMOVE_NOT_ESSENTIAL	=	yes

#######################################################################
DISTNAME	=	xc
PKGNAME		= 	XFree86-3.1.1
WRKDIR?=                ${.CURDIR}/work
BUILD_COOKIE?=		${WRKDIR}/.build_done
EXTRACT_COOKIE?=	${WRKDIR}/.extract_done
IS_INTERACTIVE=		yes
MAINTAINER=		jmz@FreeBSD.ORG

.if defined(X11_ON_X_CDROM) || defined(X11_ON_OR_CDROM)
X11_ON_CDROM	=	yes
.endif

.if defined(X11_ON_CDROM) || defined(X11_VIA_FTP)

build: configure ${BUILD_COOKIE}

${BUILD_COOKIE}:
	@echo "===>  Building for ${DISTNAME}"
.if defined(REMOVE_NOT_ESSENTIAL)
	@rm -rf ${WRKSRC}/test ${WRKSRC}/doc/hardcopy ${WRKSRC}/doc/specs
	@find ${WRKSRC}/ -name '*.orig' -exec rm -f {} ';'
.endif
	@(cd ${WRKSRC}; echo Good night...; make World)
	@touch ${WRKDIR}/.build_done

install:
	@(cd ${WRKSRC}; make install; make install.man)
	@touch ${WRKDIR}/.install_done
.if defined(X11_ON_CDROM) 
	@find /usr/X11R6/ -name 00_TRANS.TBL -exec rm -f {} ';'
.endif
.endif

.if defined(X11_ON_CDROM)
.if !defined (X11FIXES)
configure:
	@echo Edit the makefile and set X11FIXES !!!!
	@exit 1;
.endif
fetch:
	@echo -n
${EXTRACT_COOKIE}:
	@rm -rf ${WRKDIR}
	@mkdir -p ${WRKDIR}
	@echo ${X11FIXES} > ${WRKDIR}/.cdrom
	@${TOUCH} ${TOUCH_FLAGS} ${EXTRACT_COOKIE}
.if defined(X11_ON_X_CDROM)
	${TOUCH} ${TOUCH_FLAGS} ${WRKDIR}/.cd_X
.endif
.if defined(X11_ON_OR_CDROM)
	${TOUCH} ${TOUCH_FLAGS} ${WRKDIR}/.cd_OR
.endif

.elif defined(X11_VIA_FTP)
.include "Makefile.ftp"
.else
all:
	@echo -n
fetch:
	@echo -n
extract:
	@echo -n
configure:
	@echo -n
build:
	@echo -n
install:
	@echo -n
.endif

.include <bsd.port.mk>
