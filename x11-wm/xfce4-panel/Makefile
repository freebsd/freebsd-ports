# New ports collection makefile for:	xfce4-panel
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-panel
PORTVERSION=	3.99.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.xfce.org/archive/xfce4-rc2/src/ \
		ftp://ftp.unix-ag.org/user/bmeurer/xfce4/rc2/separate/ \
		http://usuarios.lycos.es/xfce4/tarballs/rc2/separate/ \
		http://linux.imp.mx/xfce4/rc2/xfce4-rc2/src/
DIST_SUBDIR=	xfce4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XFce 4 panel module

BUILD_DEPENDS=	xfce-mcs-manager:${PORTSDIR}/sysutils/xfce4-mcs-manager
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.1:${PORTSDIR}/x11-toolkits/libxfce4gui

USE_GNOME=	gtk20
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/panel/Makefile.in

.include <bsd.port.mk>
