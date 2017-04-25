# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0-p1
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	x11

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Lumina Desktop Environment

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	fluxbox>=0:x11-wm/fluxbox \
		kf5-oxygen-icons5>=0:x11-themes/kf5-oxygen-icons5 \
		xscreensaver:x11/xscreensaver \
		xbrightness:x11/xbrightness \
		compton:x11-wm/compton \
		xinput:x11/xinput \
		xrandr:x11/xrandr \
		numlockx:x11/numlockx
LIB_DEPENDS=	libxcb.so:x11/libxcb \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util

CONFLICTS=	lumina-devel-0* \
		lumina-i18n-[0-1]*

OPTIONS_DEFINE=	MULTIMEDIA TRUEOS I18N DEBUG
OPTIONS_DEFAULT=	MULTIMEDIA I18N
MULTIMEDIA_DESC=	Install multimedia support backend (gstreamer)
TRUEOS_DESC=	Use the TrueOS system interface settings.
I18N_DESC=	Install localization files.
DEBUG_DESC=	Preserve debugging information within binaries.

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMULTIMEDIA}
RUN_DEPENDS+=	gstreamer1-plugins-core>=0:multimedia/gstreamer1-plugins-core
.endif

MAKE_JOBS_UNSAFE=yes

USE_GL=		gl
USE_XORG=	x11 xdamage
USE_LDCONFIG=	yes
USE_QT5=	core gui widgets network svg multimedia imageformats \
		buildtools_build x11extras concurrent linguisttools_build
USES=		desktop-file-utils qmake
USE_GITHUB=	yes
GH_ACCOUNT=	trueos

#Setup the qmake configuration options
.if ${PORT_OPTIONS:MTRUEOS}
QMAKE_ARGS=	DEFAULT_SETTINGS=TrueOS
.endif

.if ${PORT_OPTIONS:MI18N}
QMAKE_ARGS+=	CONFIG+=WITH_I18N
.endif

.if ${PORT_OPTIONS:MDEBUG}
QMAKE_ARGS+=	CONFIG+=debug
.endif
.include <bsd.port.mk>
