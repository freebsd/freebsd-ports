PORTNAME=	xvattr
DISTVERSION=	1.3
PORTREVISION=	12
CATEGORIES=	x11
MASTER_SITES=	LOCAL/fuz
DISTNAME=	xvattr_${DISTVERSION}.orig

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Getting and setting Xv attributes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		gnome pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_XORG=	x11 xv

PLIST_FILES=	bin/xvattr bin/gxvattr \
		share/man/man1/${PORTNAME}.1.gz

CFLAGS+=	-DVERSION=\"${PORTVERSION}\"
WRKSRC=		${WRKDIR}/xvattr-${DISTVERSION}

post-extract:
	@${RM} ${WRKSRC}/getopt.h

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME} \
		`pkg-config --cflags --libs xv x11`
	cd ${WRKSRC} && ${CC} ${CFLAGS} g${PORTNAME}.c -o g${PORTNAME} \
		`pkg-config --cflags --libs gtk+-2.0 xv x11`

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/g${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
