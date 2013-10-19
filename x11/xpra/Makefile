# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpra
PORTVERSION=	0.8.8
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xpra.org/src/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Xpra gives you persistent remote applications for X

BUILD_DEPENDS=	cython:${PORTSDIR}/lang/cython \
		ipython:${PORTSDIR}/devel/ipython \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	cython:${PORTSDIR}/lang/cython \
		ipython:${PORTSDIR}/devel/ipython \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		py*-notify>=0:${PORTSDIR}/devel/py-notify \
		Xvfb:${PORTSDIR}/x11-servers/xorg-vfbserver
LIB_DEPENDS+=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg

MANCOMPRESSED=	no
MAN1=		xpra.1 xpra_launcher.1 parti.1

USES=		pkgconfig
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_XORG=	x11 xext xtst xfixes xcomposite xdamage

USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	parti_all

NO_STAGE=	yes
.include <bsd.port.mk>
