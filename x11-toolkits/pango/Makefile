# New ports collection makefile for:   pango
# Date Created:			18 July 2000
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	0.16
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.3/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.3/ \
		http://www.ameth.org/gimp/gtk/v1.3/

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS=	glib-1.3.5:${PORTSDIR}/devel/glib13 \
		freetype.6:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-qt=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

pre-patch:
	@find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		's|\$\(libdir\)/pkgconfig|\$\(prefix\)/libdata/pkgconfig|g'

.include <bsd.port.mk>
