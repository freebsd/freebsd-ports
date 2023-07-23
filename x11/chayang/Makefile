PORTNAME=	chayang
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~emersion/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Gradually dim the screen
WWW=		https://git.sr.ht/~emersion/chayang

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 meson pkgconfig
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
