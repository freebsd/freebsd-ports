# Created by: Matt Lancereau
# $FreeBSD$

PORTNAME=	xfce4-terminal
PORTVERSION=	0.6.3
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Terminal emulator for the X windowing system

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20 glib20 intltool intlhack vte libxml2
USE_XFCE=	configenv libmenu
USE_XORG=	x11
USES=		pkgconfig gmake

CONFIGURE_ARGS=	--without-gnome-default-appsdir

OPTIONS_DEFINE=	NLS

.include  <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
# Downgrade VTE to 0.26
	@${REINPLACE_CMD} -e 's|0.28|0.26|g' ${WRKSRC}/configure
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|	terminal||; \
		s|po \\|terminal|' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
