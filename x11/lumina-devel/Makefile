# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina
PORTVERSION=	20151013
CATEGORIES=	x11
PKGNAMESUFFIX=	-devel

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

CONFLICTS=	lumina-0*

OPTIONS_DEFINE=	MULTIMEDIA
OPTIONS_DEFAULT=	MULTIMEDIA
MULTIMEDIA_DESC=	Install multimedia support backend (gstreamer)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMULTIMEDIA}
RUN_DEPENDS+=	gstreamer-plugins-core>=0:${PORTSDIR}/multimedia/gstreamer-plugins-core \
		gstreamer-plugins-ogg>=0:${PORTSDIR}/audio/gstreamer-plugins-ogg \
		gstreamer-plugins-vorbis>=0:${PORTSDIR}/audio/gstreamer-plugins-vorbis
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
GH_TAGNAME=	afa8a2468f73805646eb4b3bcf143e7e2ea3140d

QMAKE_ARGS=	CONFIG+="configure NO_I18N"

.include <bsd.port.mk>
