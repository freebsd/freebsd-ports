# New ports collection makefile for:   sawfish
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sawfish
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sawmill
DISTNAME=	${PORTNAME}-${PORTVERSION}-gtk1
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lisp configurable window manager

LIB_DEPENDS=	rep.12:${PORTSDIR}/lang/librep \
		Xft.2:${PORTSDIR}/x11-fonts/Xft
BUILD_DEPENDS=	${X11BASE}/libexec/rep/${GNUHOST}/gtk.so:${PORTSDIR}/x11-toolkits/rep-gtk
RUN_DEPENDS=	${X11BASE}/libexec/rep/${GNUHOST}/gtk.so:${PORTSDIR}/x11-toolkits/rep-gtk

GNUHOST=	${ARCH}-pc-freebsd${OSREL:C/\..*//}
PLIST_SUB=	GNUHOST=${GNUHOST} VERSION=${PORTVERSION}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack gnomehier gtk12 imlib esound
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-readline
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include \
		-I${LOCALBASE}/include/freetype2" LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	${ARCH}-pc-freebsd${OSREL:C/\..*//}

.if defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD)
.undef WITHOUT_GNOME
.undef WITHOUT_ALL
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibcapplet}!="" && ${HAVE_GNOME:Mgdkpixbuf}!=""
USE_GNOME+=	libcapplet gdkpixbuf
PKGNAMESUFFIX=	-gnome
CONFIGURE_ARGS+=--enable-capplet
.else
CONFIGURE_ARGS+=--disable-capplet \
		--disable-gnome-widgets \
		--without-gdk-pixbuf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|[(]top_builddir[)]/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

post-install:
	install-info --section="X11 window manager" \
	--entry="* sawfish: (sawfish).           sawfish programming manual" \
	${PREFIX}/info/sawfish.info ${PREFIX}/info/dir

.include <bsd.port.post.mk>
