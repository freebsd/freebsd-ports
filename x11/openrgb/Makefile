PORTNAME=	openrgb
PORTVERSION=	1.0
CATEGORIES=	x11

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Software to control a multitude of RGB devices
WWW=		https://openrgb.org

LICENSE=	GPLv2

BUILD_DEPENDS=	git>0:devel/git
LIB_DEPENDS=	libGL.so:graphics/libglvnd \
		libhidapi.so:comms/hidapi \
		libmbedcrypto.so:security/mbedtls3 \
		libmbedtls.so:security/mbedtls3 \
		libmbedx509.so:security/mbedtls3

USES=		gmake gl pkgconfig qmake qt:6

USE_GITLAB=	yes
GL_ACCOUNT=	CalcProgrammer1
GL_PROJECT=	OpenRGB
GL_TAGNAME=	release_${PORTVERSION}

USE_GL=		gl
USE_QT=		base tools

post-extract:
		${MV} ${WRKSRC}/Controllers/LogitechController/LogitechHIDPP20Controller/LogitechHIDPP20Controller_Linux.cpp \
			${WRKSRC}/Controllers/LogitechController/LogitechHIDPP20Controller/LogitechHIDPP20Controller_Linux_FreeBSD.cpp

.include <bsd.port.mk>
