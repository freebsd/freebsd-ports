# New ports collection makefile for:	e16utils
# Date Created:				17 Oct 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	e16utils
PORTVERSION=	0.16
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.planetmirror.com/pub/enlightenment/e16utils/ \
		http://ftp.linux.org.uk/pub/linux/X11-winmgrs/enlightenment/e16utils/ \
		ftp://ftp.enlightenment.org/enlightenment/e16utils/
DISTFILES=	e16menuedit-0.1.tar.gz e16keyedit-0.2.tar.gz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Standalone menu and keybinding editors for enlightment 0.16

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib

SUB_STUBS=	e16menuedit-0.1 e16keyedit-0.2

do-patch:
.for i in ${SUB_STUBS}
	@cd ${WRKDIR}/${i} ; ${PATCH} -s < ${PATCHDIR}/patch-${i}
.endfor

do-build:
.for i in ${SUB_STUBS}
	@cd ${WRKDIR}/${i} ; ${SETENV} ${MAKE_ENV} ${MAKE} all
.endfor

do-install:
.for i in ${SUB_STUBS}
	@cd ${WRKDIR}/${i} ; \
	${INSTALL_PROGRAM} `${ECHO_CMD} '${i}' | ${SED} -e 's,-\(.*\),,'` \
	${PREFIX}/bin
.endfor

.include <bsd.port.mk>
