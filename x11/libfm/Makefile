# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfm
PORTVERSION=	1.2.3
CATEGORIES=	x11
MASTER_SITES=	SF/pcmanfm/PCManFM%20%2B%20Libfm%20%28tarball%20release%29/LibFM/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Core library of PCManFM file manager

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libmenu-cache.so:${PORTSDIR}/x11/menu-cache \
		libexif.so:${PORTSDIR}/graphics/libexif

USES=		desktop-file-utils gmake libtool pathfix pkgconfig \
		shared-mime-info gettext-tools tar:xz
USE_GNOME=	glib20 gtk20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --disable-static \
	--with-gtk=2
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

post-patch:
	${REINPLACE_CMD} -e 's|DATA = libfm-extra.pc|DATA =|' \
		${WRKSRC}/Makefile.in

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/xdg/libfm/libfm.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/libfm/libfm.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
