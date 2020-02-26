# Created by: johalun0@gmail.com
# $FreeBSD$

PORTNAME=	libwacom
DISTVERSIONPREFIX=libwacom-
DISTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	bb3aa6bd57c3.patch:-p1 # https://github.com/linuxwacom/libwacom/pull/217

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Adds tablet support to libinput

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev

USES=		gnome meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	linuxwacom
USE_GNOME=	glib20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
