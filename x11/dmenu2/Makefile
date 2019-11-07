# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	dmenu2
PORTVERSION=	0.0.20150210
CATEGORIES=	x11

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Fork of dmenu with many enhancements and additional options

BROKEN=		unfetchable

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USE_GITHUB=	yes
GH_ACCOUNT=	mrshankly
GH_TAGNAME=	a4eb44b

USES=		xorg
USE_XORG=	x11 xft xrender

PLIST_FILES=	bin/dmenu2 bin/dmenu2_path bin/dmenu2_run bin/stest2 \
		man/man1/dmenu2.1.gz man/man1/stest2.1.gz

OPTIONS_DEFINE=	XINERAMA
OPTIONS_DEFAULT=	XINERAMA

XINERAMA_USE=	XORG=xinerama
XINERAMA_CFLAGS=	-DXINERAMA
XINERAMA_LIBS=	-lXinerama

post-extract:
	@${LN} -sf ${FILESDIR}/dmenu2_path ${WRKSRC}

.include <bsd.port.mk>
