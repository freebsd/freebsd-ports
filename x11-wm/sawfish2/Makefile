# New ports collection makefile for:   sawfish
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sawfish
PORTVERSION=	1.0.1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sawmill

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	rep.11:${PORTSDIR}/lang/librep
BUILD_DEPENDS=	${X11BASE}/libexec/rep/${GNUHOST}/gtk.so:${PORTSDIR}/x11-toolkits/rep-gtk
RUN_DEPENDS=	${X11BASE}/libexec/rep/${GNUHOST}/gtk.so:${PORTSDIR}/x11-toolkits/rep-gtk

GNUHOST=	${ARCH}-pc-freebsd${OSREL:C/\..*//}
PLIST_SUB=	GNUHOST=${GNUHOST} VERSION=${PORTVERSION}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_IMLIB=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-readline \
		--localstatedir=${PREFIX}/share \
		--datadir=${PREFIX}/share
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	${ARCH}-pc-freebsd${OSREL:C/\..*//}

.if defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD)
.undef WITHOUT_GNOME
.undef WITHOUT_ALL
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
CONFIGURE_ARGS+=--enable-capplet
.else
CONFIGURE_ARGS+=--disable-capplet \
		--disable-gnome-widgets \
		--without-gdk-pixbuf
.endif

pre-patch:
	@${PERL} -pi -e 's^-l(pthread|c_r)^${PTHREAD_LIBS}^g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g ; \
		 s|\$$\(datadir\)/aclocal|\$$\(prefix\)/share/aclocal|g ; \
		 s|\$$\(datadir\)/locale|\$$\(prefix\)/share/locale|g'

post-install:
	install-info --section="X11 window manager" \
	--entry="* sawfish: (sawfish).           sawfish programming manual" \
	${PREFIX}/info/sawfish.info ${PREFIX}/info/dir

.include <bsd.port.post.mk>
