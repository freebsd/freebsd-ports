# New ports collection makefile for:	xfdesktop
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-desktop
PORTVERSION=	4.2.1
PORTREVISION=	0
CATEGORIES=	x11-wm xfce
MASTER_SITES=	http://www.us.xfce.org/archive/xfce-${PORTVERSION}/src/ \
		http://www.ca-us.xfce.org/archive/xfce-${PORTVERSION}/src/ \
		http://public.fh-wolfenbuettel.de/~luedickj/xfce4/xfce-${PORTVERSION}/ \
		http://hannelore.f1.fhtw-berlin.de/mirrors/xfce4/xfce-${PORTVERSION}/src/
DISTNAME=	xfdesktop-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 desktop background manager and root menu

BUILD_DEPENDS=	xfce-mcs-manager:${PORTSDIR}/sysutils/xfce4-mcs-manager \
		xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui
RUN_DEPENDS=	xfce-mcs-manager:${PORTSDIR}/sysutils/xfce4-mcs-manager \
		xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_GETTEXT=	yes
USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include \
		CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib

MAN1=		xfdesktop.1

post-patch:
	@${REINPLACE_CMD} -e 's|G_INLINE_FUNC||g' ${WRKSRC}/src/xfce-desktop.c

.include <bsd.port.mk>
