# Created by: hrkfrd@gmail.com
# $FreeBSD$

PORTNAME=	echinus
PORTVERSION=	0.4.9
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://plhk.ru/static/echinus/

MAINTAINER=	hrkfdn@gmail.com
COMMENT=	Dynamic window manager for X11 based on dwm

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		pkgconfig xorg
USE_XORG=	x11 xau xcb xdmcp xext xft xrender xrandr

FILES=		echinusrc close.xbm iconify.xbm max.xbm

PLIST_FILES=	bin/echinus \
		etc/echinus/close.xbm \
		etc/echinus/iconify.xbm \
		etc/echinus/max.xbm \
		etc/echinus/echinusrc \
		man/man1/echinus.1.gz

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} 's|-Os|${CFLAGS}|' ${WRKSRC}/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILES:S,^,${WRKSRC}/,} ${STAGEDIR}${ETCDIR}/

.include <bsd.port.mk>
