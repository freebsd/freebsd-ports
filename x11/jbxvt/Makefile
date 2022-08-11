PORTNAME=	jbxvt
PORTVERSION=	0.8
CATEGORIES=	x11

MAINTAINER=	pyrus@bsdmail.com
COMMENT=	XVT fork in xcb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms

USES=		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	jefbed
USE_XORG=	x11 xau xcb xdmcp
HAS_CONFIGURE=	yes

MAKE_ARGS=	PREFIX=${PREFIX}
ALL_TARGET=	jbxvt

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
