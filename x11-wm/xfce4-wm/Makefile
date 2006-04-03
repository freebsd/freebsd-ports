# New ports collection makefile for:	xfwm4
# Date created:		August 14, 2002
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-wm
PORTVERSION=	4.2.3.2
PORTREVISION=	1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	http://www.us.xfce.org/archive/xfce-${PORTVERSION}/src/ \
		http://www.ca-us.xfce.org/archive/xfce-${PORTVERSION}/src/ \
		http://hannelore.f1.fhtw-berlin.de/mirrors/xfce4/xfce-${PORTVERSION}/src/
DISTNAME=	xfwm4-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 window manager

BUILD_DEPENDS=	xfce-mcs-manager:${PORTSDIR}/sysutils/xfce4-mcs-manager
LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui
RUN_DEPENDS=	xfce-mcs-manager:${PORTSDIR}/sysutils/xfce4-mcs-manager

USE_GETTEXT=	yes
USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-xinerama
CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include \
		CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib

OPTIONS=	COMPOSITE "Support the experimental X11 Composite extension" off

.include <bsd.port.pre.mk>

.if defined(WITH_COMPOSITE)
CONFIGURE_ARGS+=	--enable-compositor
.endif

.include <bsd.port.post.mk>
