PORTNAME=	dmenu2
PORTVERSION=	0.2
CATEGORIES=	x11

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Fork of dmenu with many enhancements and additional options
WWW=		https://github.com/beyert/dmenu2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		xorg

USE_GITHUB=	yes
GH_ACCOUNT=	beyert

USE_XORG=	x11 xft xrender

PLIST_FILES=	bin/dmenu2 bin/dmenu2_path bin/dmenu2_run bin/stest2 \
		share/man/man1/dmenu2.1.gz share/man/man1/stest2.1.gz

OPTIONS_DEFINE=	XINERAMA
OPTIONS_DEFAULT=	XINERAMA

XINERAMA_USE=	XORG=xinerama
XINERAMA_CFLAGS=	-DXINERAMA
XINERAMA_LIBS=	-lXinerama

.include <bsd.port.mk>
