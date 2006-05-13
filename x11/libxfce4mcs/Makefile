# New ports collection makefile for:	libxfce4util
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	libxfce4mcs
PORTVERSION=	4.2.3
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	http://www.us.xfce.org/archive/xfce-${PORTVERSION}/src/ \
		http://www.ca-us.xfce.org/archive/xfce-${PORTVERSION}/src/ \
		http://public.fh-wolfenbuettel.de/~luedickj/xfce4/xfce-${PORTVERSION}/src/ \
		http://hannelore.f1.fhtw-berlin.de/mirrors/xfce4/xfce-${PORTVERSION}/src/
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 settings management library used by most XFce 4 modules

LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util

USE_GNOME=	glib20 gnomehack
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes

.if defined(WITH_GTKDOC)
BUILD_DEPENDS+=	gtkdocize:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+=--enable-gtk-doc
.else
CONFIGURE_ARGS+=--disable-gtk-doc
.endif

.include <bsd.port.mk>
