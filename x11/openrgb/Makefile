PORTNAME=	openrgb
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Software to control a multitude of RGB devices
WWW=		https://openrgb.org

LICENSE=	GPLv2

DEPRECATED=	Depends on expired security/mbedtls2
EXPIRATION_DATE=2025-03-31

BUILD_DEPENDS=	git>0:devel/git \
		hidapi>0:comms/hidapi \
		mbedtls2>0:security/mbedtls2 \
		qt5-qmake>0:devel/qt5-qmake
LIB_DEPENDS=	libGL.so:graphics/libglvnd \
		libhidapi.so:comms/hidapi \
		libmbedcrypto.so:security/mbedtls2 \
		libmbedtls.so:security/mbedtls2 \
		libmbedx509.so:security/mbedtls2

USES=		gmake gl qmake qt:5

USE_GITLAB=	yes
GL_ACCOUNT=	CalcProgrammer1
GL_PROJECT=	OpenRGB
GL_TAGNAME=	fb88964b8e514cdf4eb22da314e13f8db06a3636

USE_GL=		gl
USE_QT=		buildtools core gui linguisttools widgets

PLIST_FILES=	bin/openrgb

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/openrgb ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
