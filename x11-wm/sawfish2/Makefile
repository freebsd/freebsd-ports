# New ports collection makefile for:   sawfish
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sawfish2
PORTVERSION=	2002.05.24
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	pre-gnome2/releases/gnome-2.0-desktop-20020607
DISTNAME=	sawfish-${PORTVERSION:S/./-/g}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	rep.11:${PORTSDIR}/lang/librep2
BUILD_DEPENDS=	${X11BASE}/libexec/rep/${GNUHOST}/gui/gtk-2/gtk.so:${PORTSDIR}/x11-toolkits/rep-gtk2
RUN_DEPENDS=	${X11BASE}/libexec/rep/${GNUHOST}/gui/gtk-2/gtk.so:${PORTSDIR}/x11-toolkits/rep-gtk2

GNUHOST=	${ARCH}-pc-freebsd${OSREL:C/\..*//}
PLIST_SUB=	GNUHOST=${GNUHOST} VERSION=2.0.pre1

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_IMLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-readline \
		--localstatedir=${PREFIX}/share \
		--datadir=${PREFIX}/share \
		--enable-capplet \
		--disable-themer
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	${ARCH}-pc-freebsd${OSREL:C/\..*//}

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

.include <bsd.port.mk>
