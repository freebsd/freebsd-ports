# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate
PORTVERSION=	1.8.1
CATEGORIES=	x11 mate
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	"meta-port" for the MATE integrated X11 desktop

RUN_DEPENDS=	mate-base>=1.8.0:${PORTSDIR}/x11/mate-base \
		mate-themes>=1.8.0:${PORTSDIR}/x11-themes/mate-themes \
		mate-icon-theme-faenza>=1.8.0:${PORTSDIR}/x11-themes/mate-icon-theme-faenza \
		mate-terminal:${PORTSDIR}/x11/mate-terminal \
		mate-screensaver:${PORTSDIR}/x11/mate-screensaver \
		mate-calc:${PORTSDIR}/math/mate-calc \
		mate-screenshot:${PORTSDIR}/deskutils/mate-utils \
		mate-system-monitor:${PORTSDIR}/sysutils/mate-system-monitor \
		eom:${PORTSDIR}/graphics/eom \
		engrampa:${PORTSDIR}/archivers/engrampa \
		atril:${PORTSDIR}/graphics/atril \
		mate-volume-control:${PORTSDIR}/audio/mate-media \
		mate-power-manager:${PORTSDIR}/sysutils/mate-power-manager \
		mozo:${PORTSDIR}/deskutils/mozo \
		mate-applets>=1.8.0:${PORTSDIR}/x11/mate-applets

USE_MATE=	pluma:run

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

.include <bsd.port.mk>
