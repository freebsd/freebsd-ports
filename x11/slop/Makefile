# $FreeBSD$

PORTNAME=	slop
PORTVERSION=	7.4
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	neel@neelc.org
COMMENT=	Make a screen selection and print the selection coordinates to stdout

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libicuuc.so:devel/icu

USES=		cmake compiler:c++11-lang
USE_GL=		gl glu glew
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext xrender

USE_GITHUB=	yes
GH_ACCOUNT=	naelstrof

PLIST_FILES=	bin/slop \
		include/slop.hpp \
		lib/libslopy.so \
		lib/libslopy.so.7.4 \
		man/man1/slop.1.gz

.include <bsd.port.mk>
