# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpra
PORTVERSION=	0.14.25
CATEGORIES=	x11
MASTER_SITES=	http://xpra.org/src/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Xpra gives you persistent remote applications for X

LICENSE=	GPLv2

BUILD_DEPENDS=	cython:${PORTSDIR}/lang/cython \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow \
		Xvfb:${PORTSDIR}/x11-servers/xorg-vfbserver \
		xauth:${PORTSDIR}/x11/xauth \
		setxkbmap:${PORTSDIR}/x11/setxkbmap \
		pulseaudio:${PORTSDIR}/audio/pulseaudio \
		ssh-askpass:${PORTSDIR}/security/openssh-askpass
LIB_DEPENDS=	libwebp.so:${PORTSDIR}/graphics/webp \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libvpx.so:${PORTSDIR}/multimedia/libvpx \
		libx264.so:${PORTSDIR}/multimedia/libx264 \
		libx265.so:${PORTSDIR}/multimedia/x265

USES=		pkgconfig python tar:xz
USE_PYTHON=	distutils
USE_XORG=	x11 xcomposite xdamage xfixes xkbfile xrandr xtst
PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYTHON_VER=${PYTHON_VER}

PYDISTUTILS_PKGNAME=	xpra_all

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/xpra/xorg.conf \
	    ${STAGEDIR}${ETCDIR}/xorg.conf.sample
	${INSTALL_DATA} ${WRKSRC}/build/xpra.conf \
	    ${STAGEDIR}${ETCDIR}/xpra.conf.sample

.include <bsd.port.mk>
