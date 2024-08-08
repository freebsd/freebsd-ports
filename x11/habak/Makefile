PORTNAME=	habak
DISTVERSION=	0.2.5
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF/fvwm-crystal/habak/${DISTVERSION}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Background changing app
WWW=		https://sourceforge.net/projects/fvwm-crystal/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libImlib2.so:graphics/imlib2 \
		libX11.so:x11/libX11

USES=		localbase:ldflags

PLIST_FILES=	bin/${PORTNAME}

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME})

.include <bsd.port.mk>
