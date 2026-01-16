PORTNAME=	histui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.7
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Highly themeable GTK4 notification daemon for Wayland
WWW=		https://jmylchreest.github.io/histui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libadwaita-1.so:x11-toolkits/libadwaita \
		libasound.so:audio/alsa-lib \
		libfontconfig.so:x11-fonts/fontconfig \
		libgraphene-1.0.so:graphics/graphene \
		libgtk4-layer-shell.so:x11-toolkits/gtk4-layer-shell \
		libvulkan.so:graphics/vulkan-loader

USES=		gnome go:modules pkgconfig
USE_GNOME=	cairo gdkpixbuf gtk40 introspection

GO_MODULE=	github.com/jmylchreest/histui
GO_TARGET=	./cmd/histui ./cmd/histuid
CGO_LDFLAGS=	-s -w

PLIST_FILES=	bin/histui \
		bin/histuid

.include <bsd.port.mk>
