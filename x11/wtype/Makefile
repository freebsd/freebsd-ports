# $FreeBSD$

PORTNAME=	wtype
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	bc262ff93e55.patch:-p1 # https://github.com/atx/wtype/issues/16

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Programmatically simulate keyboard input on Wayland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	atx
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
