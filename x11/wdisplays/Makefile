# $FreeBSD$

PORTNAME=	wdisplays
PORTVERSION=	s20200314
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GUI display configurator for wlroots compositors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.17:graphics/wayland-protocols
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gtk30
GH_ACCOUNT=	cyclopsian
GH_TAGNAME=	0faafdc
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/com.github.${GH_ACCOUNT}.${GH_PROJECT}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg

.include <bsd.port.mk>
