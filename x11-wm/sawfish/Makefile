# New ports collection makefile for:   sawmill
# Version required:    0.17
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	sawmill-0.17
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.dcs.warwick.ac.uk/people/John.Harper/sawmill/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		Imlib.5:${PORTSDIR}/graphics/imlib
.if !defined(NOGNOME)
LIB_DEPENDS+=	capplet.1:${PORTSDIR}/sysutils/gnomecontrolcenter
.endif
BUILD_DEPENDS=	rep:${PORTSDIR}/lang/librep \
		${LOCALBASE}/libexec/rep/${ARCH}--freebsd${OSREL}/libgtk.so:${PORTSDIR}/x11-toolkits/rep-gtk

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

PLIST_SUB=	GNUHOST=${ARCH}--freebsd${OSREL}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
.if !defined(NOGNOME)
CONFIGURE_ARGS+=	--enable-capplet
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include\
			-I${LOCALBASE}/include/giflib" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib -lxpg4"

.include <bsd.port.mk>
