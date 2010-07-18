# New ports collection makefile for:	Xwrapper
# Date created:				2000-09-18
# Whom:					Trevor Johnson <trevor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wrapper
PORTVERSION=	1.0
PORTREVISION=	10
CATEGORIES=	x11
DISTNAME=	# intentionally left blank
EXTRACT_SUFX=	# intentionally left blank

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Wrapper for X.Org X11 server

RUN_DEPENDS=	Xorg:${PORTSDIR}/x11-servers/xorg-server

NO_WRKSUBDIR=	yes
USE_XORG=	x11
PLIST_FILES=	bin/Xwrapper

XSERVER=	-DXSERVER_PATH=\"${LOCALBASE}/bin/Xorg\"
PKGNAMEPREFIX=	xorg-

do-fetch:
	@${DO_NADA}

do-build:
	${CC} ${CFLAGS} ${XSERVER} -o ${WRKSRC}/Xwrapper ${FILESDIR}/wrapper.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xwrapper ${PREFIX}/bin
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
