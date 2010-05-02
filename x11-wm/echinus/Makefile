# New ports collection makefile for:   echinus
# Date created:		04 August 2008
# Whom:			hrkfrd@gmail.com
#
# $FreeBSD$
#

PORTNAME=	echinus
PORTVERSION=	0.4.3.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://plhk.ru/static/echinus/

MAINTAINER=	hrkfdn@gmail.com
COMMENT=	A dynamic window manager for X11 based on dwm

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_XORG=	x11 xft xrender xrandr
USE_GNOME=	pkgconfig

MAN1=		echinus.1
MANCOMPRESSED=	no

FILES=		echinusrc close.xbm iconify.xbm max.xbm

PLIST_FILES=	bin/echinus \
		etc/echinus/close.xbm \
		etc/echinus/iconify.xbm \
		etc/echinus/max.xbm \
		etc/echinus/echinusrc

PLIST_DIRS=	etc/echinus
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's/VERSION/${PORTVERSION}/g' ${WRKSRC}/echinus.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
	@${MKDIR} ${ETCDIR}
	@${INSTALL_DATA} ${FILES:S,^,${WRKSRC}/,} ${ETCDIR}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
