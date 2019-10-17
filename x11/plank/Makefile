# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	plank
PORTVERSION=	0.11.89
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/${PORTNAME}/1.0/${PORTVERSION}/+download/

MAINTAINER=	daniel@shafer.cc
COMMENT=	Elegant, simple, and clean dock

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libbamf3.so:sysutils/bamf \
		libgee-0.8.so:devel/libgee \
		libgnome-menu-3.so:x11/gnome-menus

USES=		gmake gnome libtool localbase pathfix pkgconfig tar:xz xorg
USE_GNOME=	glib20 gtk30 gdkpixbuf2 cairo intlhack libxml2 libwnck3 dconf
USE_XORG=	x11 xfixes xi

CFLAGS+=	-Wno-return-type
GNU_CONFIGURE=	yes
GLIB_SCHEMAS=	net.launchpad.plank.gschema.xml

OPTIONS_SUB=	yes

OPTIONS_DEFINE=	NLS DBUSMENU
DBUSMENU_DESC=	DBusMenu protocol

CONFIGURE_ARGS=	--disable-benchmark \
	--disable-headless-tests \
	--disable-apport

NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

DBUSMENU_LIB_DEPENDS=			libdbusmenu-gtk3.so:devel/libdbusmenu
DBUSMENU_CONFIGURE_ENABLE=		dbusmenu

INSTALLS_ICONS= yes
INSTALL_TARGET= install-strip

post-patch:
	${REINPLACE_CMD} -e 's|CPUMonitor||' \
		${WRKSRC}/docklets/Makefile.in

.include <bsd.port.mk>
