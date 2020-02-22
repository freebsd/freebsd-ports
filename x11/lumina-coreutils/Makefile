# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina-coreutils
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
CATEGORIES=	x11

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Lumina Desktop Environment

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../../LICENSE

RUN_DEPENDS=	xrandr:x11/xrandr

USES=		compiler:c++11-lang qmake qt:5
USE_QT=		buildtools_build concurrent core gui \
		imageformats multimedia network \
		svg widgets x11extras
USE_GITHUB=	yes
GH_ACCOUNT=	lumina-desktop
GH_PROJECT=	lumina

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=	yes

NLS_USE=	QT=linguist_build
NLS_QMAKE_ON=	CONFIG+=WITH_I18N

WRKSRC_SUBDIR=	src-qt5/core-utils

CONFLICTS_INSTALL=	lumina-1.2.*

.include <bsd.port.mk>
