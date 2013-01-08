# Created by: Kris Moore <kmoore@freebsd.org>
# $FreeBSD$

PORTNAME=	libfm
PORTVERSION=	1.1.0
CATEGORIES=	x11
MASTER_SITES=	SF/pcmanfm/PCManFM%20%2B%20Libfm%20%28tarball%20release%29/libfm%20%28required%20by%20PCManFM%29/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	The libFM backend library to PCManFM

LICENSE=	GPLv2

LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification \
		menu-cache.1:${PORTSDIR}/x11/menu-cache

USE_GNOME=	gnomehack gtk20
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_FAM=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--sysconfdir=${LOCALBASE}/etc

MAN1=		libfm-pref-apps.1

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-Wno-unused-but-set-variable||' \
		${WRKSRC}/src/actions/Makefile.am ${WRKSRC}/src/actions/Makefile.in

pre-install:
	cd ${WRKDIR}/libfm-${PORTVERSION} && ${CHMOD} 755 install-sh

.include <bsd.port.mk>
