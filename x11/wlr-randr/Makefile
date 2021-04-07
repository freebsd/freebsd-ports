PORTNAME=	wlr-randr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	xrandr clone for wlroots compositors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	emersion
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
