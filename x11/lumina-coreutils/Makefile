PORTNAME=	lumina-coreutils
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lumina Desktop Environment
WWW=		https://github.com/lumina-desktop/lumina/tree/master/src-qt5/core-utils

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../../LICENSE

RUN_DEPENDS=	xrandr:x11/xrandr

USES=		compiler:c++11-lang qmake qt:5
USE_QT=		buildtools:build concurrent core gui \
		imageformats multimedia network \
		svg widgets x11extras
USE_GITHUB=	yes
GH_ACCOUNT=	lumina-desktop
GH_PROJECT=	lumina

QMAKE_ARGS=	L_MANDIR=${PREFIX}/share/man

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=	yes

NLS_USE=	QT=linguist:build
NLS_QMAKE_ON=	CONFIG+=WITH_I18N

WRKSRC_SUBDIR=	src-qt5/core-utils

CONFLICTS_INSTALL=	lumina-1.2.*

.include <bsd.port.mk>
