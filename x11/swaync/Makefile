PORTNAME=	swaync
PORTVERSION=	s20210730
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple Wayland notification daemon with GUI

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell \
		libhandy-1.so:x11-toolkits/libhandy

USES=		compiler:c11 gnome localbase:ldflags meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gdkpixbuf2 gtk30
GH_ACCOUNT=	ErikReider
GH_PROJECT=	SwayNotificationCenter
GH_TAGNAME=	4abddf0
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-client

.include <bsd.port.mk>
