# New ports collection makefile for:   sawfish
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sawfish
PORTVERSION= 	0.28.1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sawmill

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		Imlib.5:${PORTSDIR}/graphics/imlib \
		rep.9:${PORTSDIR}/lang/librep
.if !defined(NOGNOME)
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
.if !defined(NOGNOME)
CONFIGURE_ARGS+=	--enable-capplet
.else
CONFIGURE_ARGS+=	--disable-capplet
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib -lxpg4"

.if defined(NOGNOME)
PLIST=		${PKGDIR}/PLIST.nognome
.endif

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
	${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	install-info --section="X11 window manager" \
	--entry="* sawfish: (sawfish).           sawfish programming manual" \
	${PREFIX}/info/sawfish.info ${PREFIX}/info/dir

.include <bsd.port.mk>
