# New ports collection makefile for:   sawfish
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sawfish2
PORTVERSION=	1.3
PORTREVISION=	7
PORTEPOCH=	2
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sawmill
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lisp configurable window manager

LIB_DEPENDS=	rep.12:${PORTSDIR}/lang/librep
BUILD_DEPENDS=	${X11BASE}/libexec/rep/${GNUHOST}/gui/gtk-2/gtk.so:${PORTSDIR}/x11-toolkits/rep-gtk2
RUN_DEPENDS=	${X11BASE}/libexec/rep/${GNUHOST}/gui/gtk-2/gtk.so:${PORTSDIR}/x11-toolkits/rep-gtk2

GNUHOST=	${ARCH}-pc-freebsd${OSREL:C/\..*//}
PLIST_SUB=	GNUHOST=${GNUHOST} VERSION=${PORTVERSION}

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier gnomehack esound
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-readline \
		--localstatedir=${PREFIX}/share \
		--datadir=${PREFIX}/share \
		--enable-capplet \
		--disable-themer \
		--with-esd
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	${ARCH}-pc-freebsd${OSREL:C/\..*//}

INFO=		sawfish

post-patch:
	@${REINPLACE_CMD} -e 's|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|[$$][(]top_builddir[)]/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

post-install:
	install-info --section="X11 window manager" \
	--entry="* sawfish: (sawfish).           sawfish programming manual" \
	${PREFIX}/info/sawfish.info ${PREFIX}/info/dir

.include <bsd.port.mk>
