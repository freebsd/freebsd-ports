# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compizconfig-python
PORTVERSION=	0.8.4
PORTREVISION=	7
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Python bindings for the compizconfig library

BUILD_DEPENDS=	\
	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
	${LOCALBASE}/libdata/pkgconfig/libcompizconfig.pc:x11-wm/libcompizconfig \
	${PYTHON_PKGNAMEPREFIX}pyrex>0:devel/pyrex@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig python:2 tar:bzip2
USE_GNOME=	glib20
USE_PYTHON=	flavors

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/compizconfig.so

.include <bsd.port.mk>
