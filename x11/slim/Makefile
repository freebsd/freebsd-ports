# New ports collection makefile for:	slim
# Date created:				8 Jan 2006
# Whom:					Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	slim
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://download.berlios.de/slim/ \
		http://depot.fsck.ch/mirror/distfiles/

MAINTAINER=	ports@fsck.ch
COMMENT=	Graphical login manager for X11, derived from Login.app

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${X11BASE}/bin/X:${X_SERVER_PORT}
BUILD_DEPENDS=	${X11BASE}/include/X11/Xft/Xft.h:${PORTSDIR}/x11-fonts/libXft

USE_X_PREFIX=	yes
USE_XLIB=	yes
USE_RC_SUBR=	slim.sh

MAN1=		slim.1

MAKEFILE=	Makefile.freebsd

pre-build:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
			${WRKSRC}/Makefile.freebsd \
			${WRKSRC}/slim.conf

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${X11BASE}/bin
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${X11BASE}/etc/${PORTNAME}.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${X11BASE}/man/man1
	@${MKDIR} ${DATADIR}/themes/default
	@${INSTALL_DATA} ${WRKSRC}/themes/default/${PORTNAME}.theme ${DATADIR}/themes/default
	@${INSTALL_DATA} ${WRKSRC}/themes/default/panel.png ${DATADIR}/themes/default
	@${INSTALL_DATA} ${WRKSRC}/themes/default/background.jpg ${DATADIR}/themes/default

post-install:
	@if [ ! -f ${X11BASE}/etc/slim.conf ]; then \
		${CP} -p ${X11BASE}/etc/slim.conf.sample ${X11BASE}/etc/slim.conf ; \
	fi

.include <bsd.port.mk>
