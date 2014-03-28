# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpra
PORTVERSION=	0.11.2
CATEGORIES=	x11
MASTER_SITES=	http://xpra.org/src/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Xpra gives you persistent remote applications for X

LICENSE=	GPLv2

BUILD_DEPENDS=	cython:${PORTSDIR}/lang/cython \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		Xvfb:${PORTSDIR}/x11-servers/xorg-vfbserver \
		xauth:${PORTSDIR}/x11/xauth \
		setxkbmap:${PORTSDIR}/x11/setxkbmap \
		pulseaudio:${PORTSDIR}/audio/pulseaudio \
		ssh-askpass:${PORTSDIR}/security/openssh-askpass
LIB_DEPENDS=	libx264.so:${PORTSDIR}/multimedia/x264 \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libvpx.so:${PORTSDIR}/multimedia/libvpx

USES=		pkgconfig
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_XORG=	x11 xtst xfixes xcomposite xdamage xrandr

USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	xpra_all

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/xpra/Xvfb/xpra.conf ${STAGEDIR}/${ETCDIR}/xpra.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/xpra/xorg.conf ${STAGEDIR}/${ETCDIR}/xorg.conf.sample

.include <bsd.port.mk>
