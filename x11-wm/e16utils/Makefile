# New ports collection makefile for:	e16utils
# Date Created:				17 Oct 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	e16utils
PORTVERSION=	0.16
PORTREVISION=	7
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://public.planetmirror.com/pub/enlightenment/e16utils/
MASTER_SITE_SUBDIR=	enlightenment
DISTFILES=	e16menuedit-0.1.tar.gz e16keyedit-0.2.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone menu and keybinding editors for enlightment 0.16

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

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
