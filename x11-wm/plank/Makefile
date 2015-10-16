# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	plank
PORTVERSION=	0.10.1
CATEGORIES=	x11-wm
MASTER_SITES=	https://launchpadlibrarian.net/220768016/ \
	https://launchpad.net/${PORTNAME}/1.0/${PORTVERSION}/+download/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Elegant, simple, and clean dock

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libbamf3.so:${PORTSDIR}/sysutils/bamf \
		libgee-0.8.so:${PORTSDIR}/devel/libgee

USES=		gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CFLAGS+=	-Wno-return-type
USE_GNOME=	glib20 gtk30 gdkpixbuf2 intlhack libxml2 libwnck3
USE_XORG=	x11 xfixes xi
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
OPTIONS_SUB=	yes

OPTIONS_DEFINE=	NLS DBUSMENU
DBUSMENU_DESC=	DBusMenu protocol

CONFIGURE_ARGS=	--enable-gee-0.8 \
	--disable-benchmark \
	--disable-headless-tests \
	--disable-apport

NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

DBUSMENU_LIB_DEPENDS=		libdbusmenu-gtk3.so:${PORTSDIR}/devel/libdbusmenu
DBUSMENU_CONFIGURE_ENABLE=	dbusmenu

.include <bsd.port.mk>
