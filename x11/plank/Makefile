PORTNAME=	plank
DISTVERSION=	0.11.100
CATEGORIES=	x11

MAINTAINER=	daniel@shafer.cc
COMMENT=	Elegant, simple, and clean dock
WWW=		https://github.com/zquestz/plank-reloaded

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbamf3.so:sysutils/bamf \
		libgee-0.8.so:devel/libgee \
		libgnome-menu-3.so:x11/gnome-menus

USES=		autoreconf gmake gnome libtool localbase pathfix pkgconfig \
		vala:build xorg
USE_GNOME=	glib20 gtk30 gdkpixbuf2 cairo libxml2 libwnck3
USE_XORG=	x11 xfixes xi

CFLAGS+=	-Wno-return-type
GNU_CONFIGURE=	yes
GLIB_SCHEMAS=	net.launchpad.plank.gschema.xml

USE_GITHUB=	yes
GH_ACCOUNT=	zquestz
GH_PROJECT=	plank-reloaded

OPTIONS_SUB=	yes

OPTIONS_DEFINE=	NLS DBUSMENU
DBUSMENU_DESC=	DBusMenu protocol

CONFIGURE_ARGS=	--disable-benchmark \
	--disable-headless-tests \
	--disable-docs \
	--disable-apport

NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

DBUSMENU_LIB_DEPENDS=			libdbusmenu-gtk3.so:devel/libdbusmenu
DBUSMENU_CONFIGURE_ENABLE=		dbusmenu

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${LOCALBASE}|g' \
		${WRKSRC}/lib/Factories/ItemFactory.vala

.include <bsd.port.mk>
