PORTNAME=	kickshaw
PORTVERSION=	0.5.26
CATEGORIES=	x11-wm
MASTER_SITES=	SAVANNAH/obladi
DISTNAME=	${PORTNAME}_${PORTVERSION}_source_only

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Menu editor for the Openbox window manager

LICENSE=	GPLv2+

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gnome pkgconfig tar:bzip2
USE_GNOME=	cairo gdkpixbuf2
MAKE_ARGS=	CC="${CC}"

OPTIONS_DEFINE=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2 GTK3

do-build do-install:
	@${DO_NADA}

.for v in 2 3
GTK${v}_USE=	GNOME=gtk${v}0
GTK${v}_PLIST_FILES=	bin/${PORTNAME}-gtk${v}

do-build-GTK${v}-on:
	${DO_MAKE_BUILD} -C ${BUILD_WRKSRC}/GTK${v}/source

do-install-GTK${v}-on:
	${INSTALL_PROGRAM} ${WRKSRC}/GTK${v}/source/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-gtk${v}
.endfor

.include <bsd.port.mk>
