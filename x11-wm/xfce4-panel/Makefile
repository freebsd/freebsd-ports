# New ports collection makefile for:	xfce4-panel
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-panel
PORTVERSION=	4.0.5
PORTREVISION=	0
CATEGORIES=	x11-wm xfce
MASTER_SITES=	ftp://ftp.berlios.de/pub/xfce-goodies/${PORTVERSION}/ \
		http://hannelore.f1.fhtw-berlin.de/mirrors/xfce4/xfce-${PORTVERSION}/src/
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 panel module

BUILD_DEPENDS=	xfce-mcs-manager:${PORTSDIR}/sysutils/xfce4-mcs-manager
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.1:${PORTSDIR}/x11-toolkits/libxfce4gui

USE_GETTEXT=	yes
USE_GNOME=	gtk20
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include \
		CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/panel/Makefile.in

.include <bsd.port.mk>
