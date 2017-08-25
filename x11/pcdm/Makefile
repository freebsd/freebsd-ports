# Created by: Joe Maloney <jmaloney@ixsystems.com>
# $FreeBSD$

PORTNAME=	pcdm
PORTVERSION=	201708251128
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

USE_QT5=        core gui network svg multimedia imageformats \
		buildtools_build x11extras concurrent
USES=           qmake
USE_OPENRC_SUBR=pcdm

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	pcdm
GH_TAGNAME=	3a369c8e18a8c82cb4123014191a2024c7228f17

.include <bsd.port.mk>
