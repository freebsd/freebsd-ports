PORTNAME=	xfishtank
PORTVERSION=	2.5
CATEGORIES=	x11
MASTER_SITES=	DEBIAN
MASTER_SITE_SUBDIR=	pool/main/x/xfishtank/
DISTNAME=	xfishtank_2.5.orig

MAINTAINER=	kidon@posteo.de
COMMENT=	Make fish swim in the background of your screen
WWW=	https://sources.debian.org/src/xfishtank/2.5-1/README

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		imake xorg
USE_XORG=	x11 xext
WRKSRC=		${WRKDIR}/xfishtank-2.5

XSSHACKSDIR=    bin/xscreensaver-hacks
XSSCONFDIR=     share/xscreensaver/config

pre-build:
	${CC} ${WRKSRC}/makeh.c -o ${WRKSRC}/makeh

post-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${XSSHACKSDIR} ${STAGEDIR}/${PREFIX}/${XSSCONFDIR}
	${CP} ${PATCHDIR}/${PORTNAME}.xml.in ${STAGEDIR}/${PREFIX}/${XSSCONFDIR}/${PORTNAME}.xml
	(cd ${STAGEDIR}/${PREFIX}/${XSSHACKSDIR} ; ${LN} -f ${STAGEDIR}/${PREFIX}/bin/${PORTNAME} ${STAGEDIR}/${PREFIX}/${XSSHACKSDIR}/)

.include <bsd.port.mk>
