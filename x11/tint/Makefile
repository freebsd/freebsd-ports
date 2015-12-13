# $FreeBSD$

PORTNAME=	tint2
PORTVERSION=	0.12.3
CATEGORIES=	x11
MASTER_SITES=	http://leigh123linux.fedorapeople.org/pub/${PORTNAME}/source/

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Lightweight freedesktop-compliant panel/taskbar/systray/clock

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libImlib2.so:${PORTSDIR}/graphics/imlib2 \
		libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification

USES=		alias cmake gettext pkgconfig
USE_GNOME=	glib20 gtk20 librsvg2 pango
USE_XORG=	x11 xcomposite xdamage xinerama xrandr xrender

CMAKE_ARGS=	-DMANDIR:PATH=man -DSYSCONFDIR:PATH=etc

OPTIONS_DEFINE=	EXAMPLES
EXAMPLES_CMAKE_ON=	-DENABLE_EXAMPLES:BOOL=ON
EXAMPLES_CMAKE_OFF=	-DENABLE_EXAMPLES:BOOL=OFF
OPTIONS_SUB=	yes

.include <bsd.port.mk>
