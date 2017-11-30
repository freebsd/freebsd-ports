# $FreeBSD$

PORTNAME=	slop
PORTVERSION=	7.3.49
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	neel@neelc.org
COMMENT=	Make a screen selection and print the selection coordinates to stdout

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libicuuc.so:devel/icu

USES=		cmake
USE_GL=		glew
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xrender

USE_GITHUB=	yes
GH_ACCOUNT=	naelstrof

PLIST_FILES=	bin/slop \
		include/slop.hpp \
		lib/libslopy.so \
		share/man/man1/slop.1.gz

.include <bsd.port.mk>
