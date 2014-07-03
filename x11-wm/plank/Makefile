# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	plank
PORTVERSION=	0.5.0
CATEGORIES=	x11-wm
MASTER_SITES=	https://launchpadlibrarian.net/156777764/ \
	https://launchpad.net/${PORTNAME}/1.0/${PORTVERSION}/+download/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Elegant, simple, and clean dock

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libbamf3.so:${PORTSDIR}/sysutils/bamf \
	libgee-0.8.so:${PORTSDIR}/devel/libgee

USES=	tar:xz pkgconfig gmake pathfix libtool
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk30 gdkpixbuf2 libxml2 libwnck3
USE_XORG=	x11
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS DBUSMENU
DBUSMENU_DESC=	DBusMenu protocol

CONFIGURE_ARGS=	--enable-gee-0.8 \
	--disable-benchmark \
	--disable-headless-tests

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDBUSMENU}
# Need GTK3 support
LIB_DEPENDS+=	libdbusmenu-gtk3.so:${PORTSDIR}/devel/libdbusmenu
CONFIGURE_ARGS+=--enable-dbusmenu
.else
CONFIGURE_ARGS+=--disable-dbusmenu
.endif

.include <bsd.port.mk>
