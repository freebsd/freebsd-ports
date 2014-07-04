# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfm
PORTVERSION=	1.2.1
CATEGORIES=	x11
MASTER_SITES=	SF/pcmanfm/PCManFM%20%2B%20Libfm%20%28tarball%20release%29/libfm%20%28required%20by%20PCManFM%29/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	LibFM backend library to PCManFM

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libmenu-cache.so:${PORTSDIR}/x11/menu-cache \
		libexif.so:${PORTSDIR}/graphics/libexif

USES=		desktop-file-utils fam gmake pkgconfig shared-mime-info tar:xz libtool
USE_GNOME=	gtk20
USE_AUTOTOOLS=	aclocal automake libtoolize:env
CONFIGURE_ARGS+=--sysconfdir=${LOCALBASE}/etc
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS NLS STATIC
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=		nls
STATIC_CONFIGURE_ENABLE=	static

PLIST_SUB+=	MAJORVER=1.0
PLIST_SUB+=	VER=4

post-patch:
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/^pkgconfigdir/s|$$(libdir)|$$(prefix)/libdata|; \
		s|libfm-gtk3.pc||' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e '/libfm.conf/ d' ${WRKSRC}/data/Makefile.am

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/libfm
	${INSTALL_DATA} ${WRKSRC}/data/libfm.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/libfm/libfm.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
