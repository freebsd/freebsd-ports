# New ports collection makefile for:   pango
# Date Created:			18 July 2000
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.3/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.3/ \
		http://www.ameth.org/gimp/gtk/v1.3/

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS=	glib-1.3.5:${PORTSDIR}/devel/glib13 \
		freetype.7:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

BROKEN=		"uses some freetype2 internals and as a result was b0rken by freetype2 upgrade"

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-qt=no

# Hmm.. tough one.  Found this one when I had graphics/hdf installed
# (which installs glist.h) which is picked up before the glib-2.0
# stuff, with Bad Results[tm]
#
GLIB2_CFLAGS=	`pkg-config glib-2.0 --cflags`
CONFIGURE_ENV=	CPPFLAGS="${GLIB2_CFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
PLIST_SUB+=	XFREE4:="@comment "
.else
PLIST_SUB+=	XFREE4:=""
.endif

pre-patch:
	@find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		's|\$\(libdir\)/pkgconfig|\$\(prefix\)/libdata/pkgconfig|g'

.include <bsd.port.post.mk>
