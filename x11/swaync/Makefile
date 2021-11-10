PORTNAME=	swaync
PORTVERSION=	s20211110
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple Wayland notification daemon with GTK panel

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell \
		libhandy-1.so:x11-toolkits/libhandy

USES=		compiler:c11 gnome localbase:ldflags meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gdkpixbuf2 gtk30 introspection:build
GH_ACCOUNT=	ErikReider
GH_PROJECT=	SwayNotificationCenter
GH_TAGNAME=	56e41f2
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-client \
		"@sample etc/xdg/${PORTNAME}/config.json.sample" \
		"@sample etc/xdg/${PORTNAME}/style.css.sample"

post-patch:
# Let @sample handle default files under etc/
	@${REINPLACE_CMD} -e "/inst.*conf/s/'[^']*/&', rename: &.sample/1" \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
