# New ports collection makefile for:	slim
# Date created:				8 Jan 2006
# Whom:					Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	slim
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_BERLIOS} \
		http://depot.fsck.ch/mirror/distfiles/
MASTER_SITE_SUBDIR=slim

MAINTAINER=	ports@fsck.ch
COMMENT=	Graphical login manager for X11, derived from Login.app

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${X11BASE}/bin/X:${X_SERVER_PORT}
BUILD_DEPENDS=	${X11BASE}/include/X11/Xft/Xft.h:${PORTSDIR}/x11-fonts/libXft

USE_XLIB=	yes
USE_RC_SUBR=	slim.sh

MAN1=		slim.1

MAKEFILE=	Makefile.freebsd

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile on FreeBSD 4.x
.endif

pre-build:
	@${REINPLACE_CMD} \
			-e 's|%%X11BASE%%|${X11BASE}|g' \
			-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			${WRKSRC}/Makefile.freebsd \
			${WRKSRC}/slim.conf

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${LOCALBASE}/bin
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${LOCALBASE}/etc/${PORTNAME}.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${LOCALBASE}/man/man1
	@${MKDIR} ${DATADIR}/themes/default
	@${INSTALL_DATA} ${WRKSRC}/themes/default/${PORTNAME}.theme ${DATADIR}/themes/default
	@${INSTALL_DATA} ${WRKSRC}/themes/default/panel.png ${DATADIR}/themes/default
	@${INSTALL_DATA} ${WRKSRC}/themes/default/background.jpg ${DATADIR}/themes/default

post-install:
	@if [ ! -f ${LOCALBASE}/etc/slim.conf ]; then \
		${CP} -p ${LOCALBASE}/etc/slim.conf.sample ${LOCALBASE}/etc/slim.conf ; \
	fi

.include <bsd.port.post.mk>
