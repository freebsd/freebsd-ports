# Created by: hrkfrd@gmail.com
# $FreeBSD$

PORTNAME=	echinus
PORTVERSION=	0.4.9
CATEGORIES=	x11-wm
MASTER_SITES=	http://plhk.ru/static/echinus/

MAINTAINER=	hrkfdn@gmail.com
COMMENT=	Dynamic window manager for X11 based on dwm

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		xcb:${PORTSDIR}/x11/libxcb \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

USE_PKGCONFIG=	build
USE_XORG=	x11 xau xdmcp xext xft xrender xrandr

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
	@${REINPLACE_CMD} 's|-Os|${CFLAGS}|' ${WRKSRC}/config.mk

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
	@${MKDIR} ${ETCDIR}
	@${INSTALL_DATA} ${FILES:S,^,${WRKSRC}/,} ${ETCDIR}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
