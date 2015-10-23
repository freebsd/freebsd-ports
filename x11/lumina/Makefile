# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina
PORTVERSION=	0.8.7
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-Release
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Lumina Desktop Environment

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	xorg>=0:${PORTSDIR}/x11/xorg \
		fluxbox>=0:${PORTSDIR}/x11-wm/fluxbox \
		fluxbox-tenr-styles-pack>=0:${PORTSDIR}/x11-themes/fluxbox-tenr-styles-pack \
		kde4-icons-oxygen>=0:${PORTSDIR}/x11-themes/kde4-icons-oxygen \
		xscreensaver:${PORTSDIR}/x11/xscreensaver \
		xscreensaver-demo:${PORTSDIR}/x11/xscreensaver \
		xbrightness:${PORTSDIR}/x11/xbrightness \
		numlockx:${PORTSDIR}/x11/numlockx

CONFLICTS=      lumina-devel-0*

OPTIONS_DEFINE=	MULTIMEDIA PCBSD
OPTIONS_DEFAULT=	MULTIMEDIA
MULTIMEDIA_DESC=	Install multimedia support backend (gstreamer)
PCBSD_DESC=	Use the PC-BSD system interface settings.

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMULTIMEDIA}
RUN_DEPENDS+=	gstreamer-plugins-core>=0:${PORTSDIR}/multimedia/gstreamer-plugins-core
.endif

MAKE_JOBS_UNSAFE=yes

USE_XORG=	x11 xdamage
USE_XCB=		x11extras wm
USE_LDCONFIG=	yes
USE_QT5=	core gui network quick svg linguist multimedia imageformats \
		buildtools x11extras concurrent
USES=		desktop-file-utils qmake
USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd

#Setup the qmake configuration options
.if {PORT_OPTIONS:MPCBSD}
QMAKE_ARGS=	CONFIG+="configure NO_I18N PCBSD"
.else
QMAKE_ARGS=	CONFIG+="configure NO_I18N"
.endif

.include <bsd.port.mk>
