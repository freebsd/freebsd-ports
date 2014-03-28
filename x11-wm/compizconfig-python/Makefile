# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compizconfig-python
PORTVERSION=	0.8.4
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for the compizconfig library

BUILD_DEPENDS=	\
	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz \
	${LOCALBASE}/libdata/pkgconfig/libcompizconfig.pc:${PORTSDIR}/x11-wm/libcompizconfig \
	${PYTHON_SITELIBDIR}/Pyrex/Distutils/__init__.py:${PORTSDIR}/devel/pyrex
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_PYTHON=	2
USES=		pathfix pkgconfig gmake tar:bzip2
USE_GNOME=	glib20
USE_AUTOTOOLS=	libtool

.include <bsd.port.mk>
