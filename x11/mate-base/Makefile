# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-base
PORTVERSION=	1.12.0
CATEGORIES=	x11 mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	"meta-port" for the MATE base integrated X11 desktop

USES=		metaport

RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSerif.ttf:x11-fonts/dejavu \
		${LOCALBASE}/share/hal/fdi/information/10freedesktop/10-camera-ptp.fdi:sysutils/hal-info \
		${LOCALBASE}/share/mate-background-properties/mate-desktop.xml:x11-themes/mate-backgrounds \
		${LOCALBASE}/bin/mate-session:x11/mate-session-manager \
		mate-themes>=1.8.0:x11-themes/mate-themes \
		mate-icon-theme-faenza>=1.8.0:x11-themes/mate-icon-theme-faenza

USE_MATE=	caja:run controlcenter:run icontheme:run \
		marco:run notificationdaemon:run panel:run \
		polkit:run

.include <bsd.port.mk>
