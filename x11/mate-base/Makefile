# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-base
PORTVERSION=	1.8.1
CATEGORIES=	x11 mate
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	"meta-port" for the MATE base integrated X11 desktop

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSerif.ttf:${PORTSDIR}/x11-fonts/dejavu \
		${LOCALBASE}/share/hal/fdi/information/10freedesktop/10-camera-ptp.fdi:${PORTSDIR}/sysutils/hal-info \
		${LOCALBASE}/share/mate-background-properties/mate-desktop.xml:${PORTSDIR}/x11-themes/mate-backgrounds \
		${LOCALBASE}/bin/mate-session:${PORTSDIR}/x11/mate-session-manager \
		mate-themes>=1.8.0:${PORTSDIR}/x11-themes/mate-themes \
		mate-icon-theme-faenza>=1.8.0:${PORTSDIR}/x11-themes/mate-icon-theme-faenza

USE_MATE=	caja:run controlcenter:run dialogs:run icontheme:run \
		marco:run notificationdaemon:run panel:run \
		polkit:run

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

.include <bsd.port.mk>
