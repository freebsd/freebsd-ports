# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdockapp
PORTVERSION=	0.6.2
PORTREVISION=	5
CATEGORIES=	x11-wm
MASTER_SITES=	LOCAL/xride

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Standard library for Window Maker dock apps

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

USES=		libtool fonts tar:bzip2
USE_LDCONFIG=	yes
USE_XORG=	xext xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-font --without-examples

post-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for file in fonts.alias *.pcf.gz
	${INSTALL_DATA} ${WRKSRC}/fonts/${file} ${STAGEDIR}${FONTSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for file in README
	${INSTALL_DATA} ${WRKSRC}/examples/${file} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/basic
.for file in Imakefile README *.c *.xpm
	${INSTALL_DATA} ${WRKSRC}/examples/basic/${file} ${STAGEDIR}${EXAMPLESDIR}/basic
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/rectangles
.for file in Imakefile *.c
	${INSTALL_DATA} ${WRKSRC}/examples/rectangles/${file} ${STAGEDIR}${EXAMPLESDIR}/rectangles
.endfor

.include <bsd.port.mk>
