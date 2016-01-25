# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate
PORTVERSION=	1.12.0
CATEGORIES=	x11 mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	"meta-port" for the MATE integrated X11 desktop

USES=		metaport

RUN_DEPENDS=	mate-base>=1.8.0:${PORTSDIR}/x11/mate-base \
		mate-themes>=1.8.0:${PORTSDIR}/x11-themes/mate-themes \
		mate-icon-theme-faenza>=1.8.0:${PORTSDIR}/x11-themes/mate-icon-theme-faenza \
		mate-terminal:${PORTSDIR}/x11/mate-terminal \
		mate-screensaver:${PORTSDIR}/x11/mate-screensaver \
		galculator:${PORTSDIR}/math/galculator \
		mate-screenshot:${PORTSDIR}/deskutils/mate-utils \
		mate-system-monitor:${PORTSDIR}/sysutils/mate-system-monitor \
		eom:${PORTSDIR}/graphics/eom \
		engrampa:${PORTSDIR}/archivers/engrampa \
		atril:${PORTSDIR}/graphics/atril \
		mate-volume-control:${PORTSDIR}/audio/mate-media \
		mate-power-manager:${PORTSDIR}/sysutils/mate-power-manager \
		caja-sendto:${PORTSDIR}/deskutils/caja-extensions \
		mozo:${PORTSDIR}/deskutils/mozo \
		mate-applets>=1.8.0:${PORTSDIR}/x11/mate-applets

USE_MATE=	pluma:run

.include <bsd.port.mk>
