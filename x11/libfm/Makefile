# Created by: Kris Moore <kmoore@freebsd.org>
# $FreeBSD$

PORTNAME=	libfm
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SF/pcmanfm/PCManFM%20%2B%20Libfm%20%28tarball%20release%29/libfm%20%28required%20by%20PCManFM%29/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	The libFM backend library to PCManFM

LICENSE=	GPLv2

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	menu-cache:${PORTSDIR}/x11/menu-cache

USES=		pkgconfig
USE_GNOME=	gnomehack gtk20
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS+=--sysconfdir=${LOCALBASE}/etc
USE_GMAKE=	yes
USE_FAM=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		libfm-pref-apps.1

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-Wno-unused-but-set-variable||' \
		${WRKSRC}/src/actions/Makefile.am ${WRKSRC}/src/actions/Makefile.in
	@${REINPLACE_CMD} -e '/libfm.conf/,/pref-apps.conf/ d' ${WRKSRC}/data/Makefile.in

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|src po|src|' \
		${WRKSRC}/Makefile.in
.endif

pre-install:
	@(cd ${WRKDIR}/libfm-${PORTVERSION} && ${CHMOD} 755 install-sh)

post-install:
	@${MKDIR} ${PREFIX}/etc/xdg/libfm
	${INSTALL_DATA} ${WRKSRC}/data/libfm.conf ${PREFIX}/etc/xdg/libfm/libfm.conf.sample
	${INSTALL_DATA} ${WRKSRC}/data/pref-apps.conf ${PREFIX}/etc/xdg/libfm/pref-apps.conf.sample
	@[ -f ${PREFIX}/etc/xdg/libfm/libfm.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/data/libfm.conf ${PREFIX}/etc/xdg/libfm/libfm.conf
	@[ -f ${PREFIX}/etc/xdg/libfm/pref-apps.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/data/pref-apps.conf ${PREFIX}/etc/xdg/libfm/pref-apps.conf
.include <bsd.port.mk>
