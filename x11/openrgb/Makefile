PORTNAME=	openrgb
PORTVERSION=	0.7.20220505
CATEGORIES=	x11

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Software to control a multitude of (a)RGB devices

LICENSE=	GPLv2

BUILD_DEPENDS=	git>0:devel/git \
		hidapi>0:comms/hidapi \
		mbedtls>0:security/mbedtls \
		qt5-qmake>0:devel/qt5-qmake
LIB_DEPENDS=	libGL.so:graphics/libglvnd \
		libhidapi.so:comms/hidapi \
		libmbedcrypto.so:security/mbedtls \
		libmbedtls.so:security/mbedtls \
		libmbedx509.so:security/mbedtls

USES=		gmake gl qmake qt:5

USE_GITLAB=	yes
GL_ACCOUNT=	CalcProgrammer1
GL_PROJECT=	OpenRGB
GL_COMMIT=	817d5d55dfb2baf932effe9fec9c557ad1529eb9

USE_GL=		gl
USE_QT=		buildtools core gui widgets

PLIST_FILES=	bin/openrgb

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/openrgb ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
