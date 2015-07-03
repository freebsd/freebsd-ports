# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpra
PORTVERSION=	0.15.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xpra.org/src/

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Xpra gives you persistent remote applications for X

LICENSE=	GPLv2

BUILD_DEPENDS=	cython:${PORTSDIR}/lang/cython \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/lz4.so:${PORTSDIR}/archivers/py-lz4 \
		pulseaudio:${PORTSDIR}/audio/pulseaudio \
		${PYTHON_SITELIBDIR}/rencode/__init__.py:${PORTSDIR}/converters/py-rencode \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl \
		${PYTHON_SITELIBDIR}/OpenGL_accelerate/__init__.py:${PORTSDIR}/graphics/py-opengl-accelerate \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_SITELIBDIR}/avahi/__init__.py:${PORTSDIR}/net/py-avahi \
		${PYTHON_SITELIBDIR}/netifaces.so:${PORTSDIR}/net/py-netifaces \
		${PYTHON_SITELIBDIR}/cups.so:${PORTSDIR}/print/py-cups \
		ssh-askpass:${PORTSDIR}/security/openssh-askpass \
		setxkbmap:${PORTSDIR}/x11/setxkbmap \
		xauth:${PORTSDIR}/x11/xauth \
		Xvfb:${PORTSDIR}/x11-servers/xorg-vfbserver \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gtkgl/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkglext
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

post-patch:
	${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|' \
	    ${WRKSRC}/xpra/platform/pycups_printing.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/xpra/xorg.conf \
	    ${STAGEDIR}${ETCDIR}/xorg.conf.sample
	${INSTALL_DATA} ${WRKSRC}/build/etc/xpra/xpra.conf \
	    ${STAGEDIR}${ETCDIR}/xpra.conf.sample

.include <bsd.port.mk>
