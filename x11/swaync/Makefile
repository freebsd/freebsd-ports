PORTNAME=	swaync
PORTVERSION=	s20210802
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple Wayland notification daemon with GTK panel

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell

USES=		compiler:c11 gnome localbase:ldflags meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gdkpixbuf2 gtk30 introspection:build
GH_ACCOUNT=	ErikReider
GH_PROJECT=	SwayNotificationCenter
GH_TAGNAME=	9d5f328
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-client \
		etc/xdg/${PORTNAME}/style.css

.include <bsd.port.mk>
