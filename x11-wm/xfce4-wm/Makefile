# New ports collection makefile for:	xfwm4
# Date created:		August 14, 2002
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-wm
PORTVERSION=	3.99.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.xfce.org/archive/xfce4-rc2/src/ \
		ftp://ftp.unix-ag.org/user/bmeurer/xfce4/rc2/separate/ \
		http://usuarios.lycos.es/xfce4/tarballs/rc2/separate/ \
		http://linux.imp.mx/xfce4/rc2/xfce4-rc2/src/
DISTNAME=	xfwm4-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XFce 4 window manager

BUILD_DEPENDS=	xfce-mcs-manager:${PORTSDIR}/sysutils/xfce4-mcs-manager
LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification

USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-xinerama

.include <bsd.port.mk>
