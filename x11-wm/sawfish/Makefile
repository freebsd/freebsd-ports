# New ports collection makefile for:   sawfish
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sawfish
PORTVERSION= 	0.31
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sawmill

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		Imlib.5:${PORTSDIR}/graphics/imlib \
		rep.10:${PORTSDIR}/lang/librep
.if !defined(WITHOUT_GNOME)
LIB_DEPENDS+=	capplet.4:${PORTSDIR}/sysutils/gnomecontrolcenter
.endif
BUILD_DEPENDS=	${LOCALBASE}/libexec/rep/${ARCH}--freebsd${OSREL}/gtk.so:${PORTSDIR}/x11-toolkits/rep-gtk
RUN_DEPENDS=	${LOCALBASE}/libexec/rep/${ARCH}--freebsd${OSREL}/gtk.so:${PORTSDIR}/x11-toolkits/rep-gtk

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

PLIST_SUB=	GNUHOST=${ARCH}--freebsd${OSREL} VERSION=${PORTVERSION}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share \
		--datadir=${PREFIX}/share --with-readline
.if !defined(WITHOUT_GNOME)
CONFIGURE_ARGS+=	--enable-capplet
PLIST_SUB+=	GNOME:=""
.else
CONFIGURE_ARGS+=	--disable-capplet \
			--disable-gnome-widgets \
			--without-gdk-pixbuf
PLIST_SUB+=	GNOME:="@comment "
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib -lxpg4"

pre-patch:
	find ${WRKSRC} \( -name "*.jl" -or -name "*.jl.in" \) | \
		xargs ${GREP} -l "../locale" | \
		xargs ${PERL} -pi -e "s|\.\./locale|../../../locale|g"

post-install:
	install-info --section="X11 window manager" \
	--entry="* sawfish: (sawfish).           sawfish programming manual" \
	${PREFIX}/info/sawfish.info ${PREFIX}/info/dir

.include <bsd.port.mk>
