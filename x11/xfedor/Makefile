# New ports collection makefile for:    xfedor
# Date created:         3 Sep 1996
# Whom:                 ache
#
# ATTENTION: It not work in > 256 colors modes, please fix it
# if you can.
#
# $FreeBSD$
#

PORTNAME=	xfedor
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/x11/util/
DISTNAME=	${PORTNAME}

MAINTAINER=	ache@FreeBSD.org
COMMENT=	A .bdf fonts/.xbm bitmaps/.xpm colored pixmaps/mouse cursor editor

USE_IMAKE=	yes
USE_XPM=	yes

XFHELP=		${X11BASE}/lib/X11/xfedor # See patches too
XCAT1=		${X11BASE}/man/cat1

do-install:
	cd ${WRKSRC}; \
	${INSTALL_PROGRAM} xfedor ${PREFIX}/bin
	-${MKDIR} ${XFHELP}
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${XFHELP}
	${CHMOD} 755 ${XFHELP}
	cd ${WRKSRC}/help; \
	${INSTALL_DATA} * ${XFHELP}
	${INSTALL_DATA} ${FILESDIR}/default.sos ${XFHELP}
	cd ${WRKSRC}; \
	${INSTALL_MAN} xfedor.txt ${XCAT1}/xfedor.1

.include <bsd.port.mk>
