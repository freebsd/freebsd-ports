# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/x11/gnome-desktop/Makefile 19546 2014-04-16 12:35:04Z gusi $

PORTNAME=	gnome-desktop
PORTVERSION=	3.12.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for GNOME 3

USES=		tar:xz

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas \
		${LOCALBASE}/libdata/pkgconfig/xkeyboard-config.pc:${PORTSDIR}/x11/xkeyboard-config \
		${LOCALBASE}/libdata/pkgconfig/xkbfile.pc:${PORTSDIR}/x11/libxkbfile \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas \
		${LOCALBASE}/libdata/pkgconfig/xkeyboard-config.pc:${PORTSDIR}/x11/xkeyboard-config \
		${LOCALBASE}/libdata/pkgconfig/xkbfile.pc:${PORTSDIR}/x11/libxkbfile

USES+=		bison gettext gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	gnomeprefix gtk30 intlhack introspection:build \
		referencehack
USE_XORG=	x11 xrandr xext
USE_PYTHON=	3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gnome-distributor="FreeBSD GNOME Project"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|xsltproc -o| xsltproc --nonet -o|g' \
		${WRKSRC}/desktop-docs/fdl/Makefile.in \
		${WRKSRC}/desktop-docs/gpl/Makefile.in \
		${WRKSRC}/desktop-docs/lgpl/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnome-desktop-3.so.10

.include <bsd.port.mk>

.endif
