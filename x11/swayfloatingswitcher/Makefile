PORTNAME=	swayfloatingswitcher
PORTVERSION=	s20221131
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Alt+Tab switcher for floating windows
WWW=		https://github.com/ErikReider/SwayFloatingSwitcher

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	granite>0:x11-toolkits/granite
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libgee-0.8.so:devel/libgee \
		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell

USES=		gnome localbase:ldflags meson pkgconfig vala:build
USE_GITHUB=	yes
USE_GNOME=	cairo gtk30
GH_ACCOUNT=	ErikReider
GH_PROJECT=	SwayFloatingSwitcher
GH_TAGNAME=	56a9e35
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-client

.include <bsd.port.mk>
