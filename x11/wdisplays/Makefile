# $FreeBSD$

PORTNAME=	wdisplays
PORTVERSION=	s20190924
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	bfaf2211c0be.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GUI display configurator for wlroots compositors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.17:graphics/wayland-protocols
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libwayland-client.so:graphics/wayland

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gtk30
GH_ACCOUNT=	cyclopsian
GH_TAGNAME=	049bf5b
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
