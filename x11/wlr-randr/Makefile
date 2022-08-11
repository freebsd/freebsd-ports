PORTNAME=	wlr-randr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~emersion/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	xrandr clone for wlroots compositors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		meson pkgconfig
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
