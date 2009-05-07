# New ports collection makefile for:	slim
# Date created:				8 Jan 2006
# Whom:					Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	slim
PORTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_BERLIOS} \
		http://depot.fsck.ch/mirror/distfiles/
MASTER_SITE_SUBDIR=slim

MAINTAINER=	ports@fsck.ch
COMMENT=	Graphical login manager for X11, derived from Login.app

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

USE_XORG=	x11 xft xmu xorg-server xrender
USE_RC_SUBR=	slim.sh
SUB_FILES=	pkg-message

MAN1=		slim.1

MAKEFILE=	Makefile.freebsd

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			${WRKSRC}/${PORTNAME}.conf

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
	@${MKDIR} ${DATADIR}/themes/default
	@${INSTALL_DATA} ${WRKSRC}/themes/default/${PORTNAME}.theme ${DATADIR}/themes/default
	@${INSTALL_DATA} ${WRKSRC}/themes/default/panel.png ${DATADIR}/themes/default
	@${INSTALL_DATA} ${WRKSRC}/themes/default/background.jpg ${DATADIR}/themes/default

post-install:
	@if [ ! -f ${PREFIX}/etc/slim.conf ]; then \
		${INSTALL_DATA} -p ${WRKSRC}/slim.conf ${PREFIX}/etc/slim.conf ; \
	fi
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
