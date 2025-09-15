PORTNAME=	plank
DISTVERSION=	0.11.149
CATEGORIES=	x11

MAINTAINER=	daniel@shafer.cc
COMMENT=	Elegant, simple, and clean dock
WWW=		https://github.com/zquestz/plank-reloaded

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbamf3.so:sysutils/bamf \
		libgee-0.8.so:devel/libgee \
		libgnome-menu-3.so:x11/gnome-menus
RUN_DEPENDS=	upower>0:sysutils/upower

USES=		desktop-file-utils gettext-runtime gettext-tools gnome \
		meson pkgconfig vala:build xorg
USE_GITHUB=	yes
GH_ACCOUNT=	zquestz
GH_PROJECT=	plank-reloaded
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 libwnck3
GLIB_SCHEMAS=	net.launchpad.plank.gschema.xml
USE_XORG=	x11 xfixes xi

MESON_ARGS=	-Dproduction-release=true \
		-Denable-apport=false \
		-Denable-barriers=yes

OPTIONS_DEFINE=	DBUSMENU
OPTIONS_SUB=	yes
DBUSMENU_DESC=	DBusMenu protocol
DBUSMENU_LIB_DEPENDS=	libdbusmenu-gtk3.so:devel/libdbusmenu
DBUSMENU_MESON_YES=	enable-dbusmenu

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/lib/Factories/ItemFactory.vala

.include <bsd.port.mk>
