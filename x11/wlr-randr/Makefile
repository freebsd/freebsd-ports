PORTNAME=	wlr-randr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	xrandr clone for wlroots compositors
WWW=		https://sr.ht/~emersion/wlr-randr/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	emersion
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
