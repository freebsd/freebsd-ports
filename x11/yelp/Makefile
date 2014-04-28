# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/x11/yelp/Makefile 19337 2014-03-25 19:31:08Z kwm $

PORTNAME=	yelp
PORTVERSION=	3.12.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Help browser for the GNOME 3 desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/yelp-xsl.pc:${PORTSDIR}/textproc/yelp-xsl \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/yelp-xsl.pc:${PORTSDIR}/textproc/yelp-xsl

USES=		desktop-file-utils gettext gmake libtool:keepla pathfix \
		pkgconfig tar:xz
USE_XORG=	x11 ice
USE_GNOME=	gnomeprefix gtk30 intlhack libxml2 libxslt
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -fstack-protector
GLIB_SCHEMAS=	org.gnome.yelp.gschema.xml

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900012 || (${OSVERSION} >= 800505 && ${OSVERSION} < 900000)
CONFIGURE_ENV+=	YELP_LZMA_CFLAGS="-I/usr/include" \
		YELP_LZMA_LIBS="-L/usr/lib -llzma"
.else
LIB_DEPENDS+=	liblzma.so:${PORTSDIR}/archivers/xz
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libyelp.so.*

.include <bsd.port.post.mk>
