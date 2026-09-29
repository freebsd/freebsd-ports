PORTNAME=	zutty
DISTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://git.hq.sig7.se/zutty.git/snapshot/${ZUTTY_COMMIT}?dummy=/

MAINTAINER=	flo@purplekraken.com
COMMENT=	High-end terminal for low-end systems
WWW=		https://tomscii.sig7.se/zutty/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2
RUN_DEPENDS=	font-misc-misc>1.1.0:x11-fonts/font-misc-misc

USES=		gl pkgconfig waf xorg
USE_GL=		egl glesv2
USE_XORG=	x11 xmu xt

WRKSRC=		${WRKDIR}/${PORTNAME}-4b6bfc1
ZUTTY_COMMIT=	4b6bfc16be46c4e1f45959ff76e7b6ce047af8a6

PLIST_FILES=	bin/zutty \
		share/applications/zutty.desktop \
		share/icons/zutty.svg \
		share/icons/zutty_128x128.png \
		share/icons/zutty_16x16.png \
		share/icons/zutty_32x32.png \
		share/icons/zutty_48x48.png \
		share/icons/zutty_64x64.png \
		share/icons/zutty_96x96.png

pre-install:
	${STRIP_CMD} ${WRKSRC}/build/src/zutty

post-install:
	${INSTALL_DATA} ${WRKSRC}/icons/zutty.desktop \
	    ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/icons/zutty.svg \
	    ${STAGEDIR}${PREFIX}/share/icons/zutty.svg
.for size in 16 32 48 64 96 128
	${INSTALL_DATA} ${WRKSRC}/icons/zutty_${size}x${size}.png \
	    ${STAGEDIR}${PREFIX}/share/icons
.endfor

.include <bsd.port.mk>
