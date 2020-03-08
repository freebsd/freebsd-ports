# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compizconfig-python
PORTVERSION=	0.8.4
PORTREVISION=	9
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Python bindings for the compizconfig library

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	\
	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
	${LOCALBASE}/libdata/pkgconfig/libcompizconfig.pc:x11-wm/libcompizconfig \
	${PYTHON_PKGNAMEPREFIX}pyrex>0:devel/pyrex@${PY_FLAVOR}
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		gmake gnome libtool pathfix pkgconfig python:2.7 tar:bzip2 xorg
USE_GNOME=	glib20 libxml2 libxslt
USE_PYTHON=	flavors
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xrandr

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/compizconfig.so

.include <bsd.port.mk>
