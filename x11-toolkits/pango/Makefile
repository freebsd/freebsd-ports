# New ports collection makefile for:   pango
# Date Created:			18 July 2000
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	0.23
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.3/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.3/ \
		http://www.ameth.org/gimp/gtk/v1.3/

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS=	glib-1.3.12:${PORTSDIR}/devel/glib13 \
		freetype.8:${PORTSDIR}/print/freetype2 \
		intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt=no

# Hmm.. tough one.  Found this one when I had graphics/hdf installed
# (which installs glist.h) which is picked up before the glib-2.0
# stuff, with Bad Results[tm]
#
GLIB2_CFLAGS=	`pkg-config glib-2.0 --cflags`
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/freetype2 \
			${GLIB2_CFLAGS} -I${LOCALBASE}/include \
			-I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
PLIST_SUB+=	XFREE4:="@comment "
.else
PLIST_SUB+=	XFREE4:=""
.endif

pre-patch:
	@find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		's|\$\(libdir\)/pkgconfig|\$\(prefix\)/libdata/pkgconfig|g'
	@find ${WRKSRC}/pango/opentype -name "*.[ch]" | xargs ${PERL} -pi -e \
		's|internal/tterrors\.h|fterrors.h| ; s|TT_Err_|FT_Err_|g'

.include <bsd.port.post.mk>
