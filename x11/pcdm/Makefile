# Created by: Joe Maloney <jmaloney@ixsystems.com>
# $FreeBSD$

PORTNAME=	pcdm
PORTVERSION=	201711221025
CATEGORIES=	x11

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	QT5 based display manager for FreeBSD

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=    xorg-minimal>=0:x11/xorg-minimal \
		xhost:x11/xhost \
		setxkbmap:x11/setxkbmap \
		${LOCALBASE}/bin/qsudo:sysutils/qsudo

WRKSRC_SUBDIR=  src-qt5
MAKE_ARGS=      PREFIX=${STAGEDIR}${PREFIX}

CONFLICTS=      pcbsd-utils-qt*

USES=           qmake
USE_QT5=        core gui network svg multimedia imageformats \
		buildtools_build x11extras concurrent

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	pcdm
GH_TAGNAME=	2879cdddfd8d630935052bc9ff905df8f6f00be0

.include <bsd.port.mk>
