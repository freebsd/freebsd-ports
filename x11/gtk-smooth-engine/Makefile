# New ports collection makefile for:    gtk-smooth-engine
# Date created:         19 November 2003
# Whom:                 Anish Mistry
# $FreeBSD$
#

PORTNAME=	gtk-smooth-engine
PORTVERSION=	0.5.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	smooth-engine

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Flexible GTK Theme Engine

.if exists(${X11BASE}/lib/libgtk-x11-2.0.so.200)
WITH_GTK2=	yes
.endif

.if exists(${X11BASE}/lib/libgtk12.so.2)
WITH_GTK12=	yes
.endif

.if defined(WITH_GTK12)
LIB_DEPENDS+=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
.endif

# if neither gtk is detected automatically pull in gtk2
.if !defined(WITH_GTK12) && !defined(WITH_GTK2)
WITH_GTK2=	yes
.endif

.if defined(WITH_GTK2)
LIB_DEPENDS+=	gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20
.endif

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gtk12 gtk20
INSTALLS_SHLIB=	yes
SHLIB_VERSION=	0

pre-everything::
.if !defined(WITH_GTK2)
	@${ECHO_MSG} "To enable gtk2 support define WITH_GTK2."
.endif

.if !defined(WITH_GTK12)
	@${ECHO_MSG} "To enable gtk12 support define WITH_GTK12."
.endif

post-install:
# add shared lib link
	@${LN} -sf libsmooth.so \
		${X11BASE}/lib/gtk-2.0/2.2.0/engines/libsmooth.so.${SHLIB_VERSION}

.include <bsd.port.mk>
