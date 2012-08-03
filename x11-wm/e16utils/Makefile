# New ports collection makefile for:	e16utils
# Date Created:				17 Oct 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	e16utils
PORTVERSION=	0.16
PORTREVISION=	11
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	SF/enlightenment/e16menuedit/e16menuedit:src1 \
		SF/enlightenment/e16keyedit/0.2:src2

DISTFILES=	e16menuedit-0.1.tar.gz:src1 \
		e16keyedit-0.2.tar.gz:src2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone menu and keybinding editors for enlightenment 0.16

LIB_DEPENDS=	gdbm.4:${PORTSDIR}/databases/gdbm

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
