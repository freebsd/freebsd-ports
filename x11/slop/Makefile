# $FreeBSD$

PORTNAME=	slop
PORTVERSION=	7.5
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Make a screen selection and print the selection coordinates to stdout

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libicuuc.so:devel/icu

USES=		cmake compiler:c++11-lang gl xorg
USE_GL=		gl glu glew
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext xrender

USE_GITHUB=	yes
GH_ACCOUNT=	naelstrof

PLIST_FILES=	bin/slop \
		include/slop.hpp \
		lib/libslopy.so \
		lib/libslopy.so.${PORTVERSION} \
		man/man1/slop.1.gz

.include <bsd.port.mk>
