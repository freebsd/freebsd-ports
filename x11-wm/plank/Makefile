# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	plank
PORTVERSION=	0.11.2
CATEGORIES=	x11-wm
MASTER_SITES=	https://launchpadlibrarian.net/263736736/ \
	https://launchpad.net/${PORTNAME}/1.0/${PORTVERSION}/+download/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Elegant, simple, and clean dock

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libbamf3.so:sysutils/bamf \
		libgee-0.8.so:devel/libgee

USES=		gmake libtool localbase pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-return-type
USE_GNOME=	glib20 gtk30 gdkpixbuf2 cairo intlhack libxml2 libwnck3 dconf
USE_XORG=	x11 xfixes xi
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

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

DBUSMENU_LIB_DEPENDS=		libdbusmenu-gtk3.so:devel/libdbusmenu
DBUSMENU_CONFIGURE_ENABLE=	dbusmenu

.include <bsd.port.mk>
