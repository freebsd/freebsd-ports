# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdockapp
PORTVERSION=	0.7.2
CATEGORIES=	x11-wm
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Standard library for Window Maker dock apps

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	mkfontdir:x11-fonts/mkfontscale

USES=		autoreconf fonts libtool pkgconfig xorg
USE_LDCONFIG=	yes
USE_XORG=	fontutil x11 xext xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-font --without-examples

WRKSRC=		${WRKDIR}/dockapps-b9baa8f

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for file in *.pcf.gz
	${INSTALL_DATA} ${WRKSRC}/fonts/${file} ${STAGEDIR}${FONTSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for file in README
	${INSTALL_DATA} ${WRKSRC}/examples/${file} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/basic
.for file in README *.c *.xpm
	${INSTALL_DATA} ${WRKSRC}/examples/basic/${file} ${STAGEDIR}${EXAMPLESDIR}/basic
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/rectangles
.for file in *.c
	${INSTALL_DATA} ${WRKSRC}/examples/rectangles/${file} ${STAGEDIR}${EXAMPLESDIR}/rectangles
.endfor

.include <bsd.port.mk>
