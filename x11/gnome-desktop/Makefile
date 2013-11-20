# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-desktop3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-desktop
PORTVERSION=	3.6.2
PORTREVISION?=	0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for GNOME 3

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas \
		${LOCALBASE}/libdata/pkgconfig/xkeyboard-config.pc:${PORTSDIR}/x11/xkeyboard-config \
		${LOCALBASE}/libdata/pkgconfig/xkbfile.pc:${PORTSDIR}/x11/libxkbfile \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas \
		${LOCALBASE}/libdata/pkgconfig/xkeyboard-config.pc:${PORTSDIR}/x11/xkeyboard-config \
		${LOCALBASE}/libdata/pkgconfig/xkbfile.pc:${PORTSDIR}/x11/libxkbfile

USE_XORG=	x11 xrandr xext
USES=		bison gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack gtk30 ltverhack referencehack \
		introspection:build
USE_PYTHON=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-gnome-distributor="FreeBSD GNOME Project"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|xsltproc -o| xsltproc --nonet -o|g' \
		${WRKSRC}/desktop-docs/fdl/Makefile.in \
		${WRKSRC}/desktop-docs/gpl/Makefile.in \
		${WRKSRC}/desktop-docs/lgpl/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnome-desktop-3.so.4

.include <bsd.port.mk>

.endif
