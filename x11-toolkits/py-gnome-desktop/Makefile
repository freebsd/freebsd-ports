# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/py-gnome-desktop/Makefile,v 1.103 2010/09/30 06:27:40 kwm Exp $

PORTNAME=	gnome-desktop
PORTVERSION=	2.32.0
PORTREVISION=	7
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gnome-python-desktop/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gnome-python-desktop-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings used by modules in the GNOME Desktop

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

BUILD_DEPENDS=	bug-buddy:${PORTSDIR}/devel/bug-buddy \
		metacity<2.34.0:${PORTSDIR}/x11-wm/metacity
LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libtotem-plparser.so:${PORTSDIR}/multimedia/totem-pl-parser \
		libgnome-media-profiles.so:${PORTSDIR}/audio/gnome-media \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libbrasero-media.so:${PORTSDIR}/sysutils/brasero \
		libevdocument.so:${PORTSDIR}/graphics/evince
RUN_DEPENDS=	bug-buddy:${PORTSDIR}/devel/bug-buddy

USES=		gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_PYTHON=	2
USE_GNOME=	libgnomeprintui gnomepanel gnomedesktop \
		gtksourceview libwnck nautilus2 pygnome2 metacity \
		evolutiondataserver
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-metacity --disable-nautilusburn
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

EG_SRC_DIR=	${WRKSRC}/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gnome

post-patch:
	@${FIND} ${WRKSRC}/docs -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^HTML_DIR =.*|HTML_DIR = ${DOCSDIR}|g'
	@${REINPLACE_CMD} -e 's|2.30|2.32|g' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${EG_DST_DIR}
	cd ${EG_SRC_DIR}; ${COPYTREE_SHARE} . ${STAGEDIR}${EG_DST_DIR}
	${RM} -rf ${STAGEDIR}${EG_DST_DIR}/nautilusburn

.include <bsd.port.mk>
