PORTNAME=	jbxvt
DISTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	pyrus@bsdmail.com
COMMENT=	XVT terminal emulator fork in XCB
WWW=		https://github.com/alisabedard/jbxvt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-cursor.so:x11/xcb-util-cursor

USES=		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	alisabedard
USE_XORG=	x11 xau xcb xdmcp
HAS_CONFIGURE=	yes

MAKE_ARGS=	PREFIX=${PREFIX}
ALL_TARGET=	jbxvt

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
