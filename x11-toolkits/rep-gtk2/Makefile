# New ports collection makefile for:   rep-gtk
# Version required:    0.6
# Date created:        06 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	rep-gtk-0.6
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.dcs.warwick.ac.uk/people/John.Harper/librep/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile \
		rep:${PORTSDIR}/lang/librep

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

PLIST_SUB=	GNUHOST=${ARCH}--freebsd${OSREL}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
			-I${LOCALBASE}/include/giflib" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
