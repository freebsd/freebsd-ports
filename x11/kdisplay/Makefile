PORTNAME=	kdisplay
DISTVERSIONPREFIX=	v
DISTVERSION=	6.2.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	App and daemon for display managing
WWW=		https://github.com/winft/kdisplay

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LGPL

LIB_DEPENDS=	libdisman.so:x11/disman

USES=		cmake:testing gettext-tools kde:6 qt:6
USE_GITHUB=	yes
USE_KDE=	ecm:build config coreaddons dbusaddons globalaccel i18n \
		itemmodels:run kcmutils layer-shell-qt libplasma windowsystem xmlgui
USE_LDCONFIG=	yes
USE_QT=		base declarative sensors
GH_ACCOUNT=	winft
PLIST_SUB=	VERSION=${PORTVERSION}
LDFLAGS+=	-Wl,--as-needed # X11, GL, KF6*

.include <bsd.port.mk>
