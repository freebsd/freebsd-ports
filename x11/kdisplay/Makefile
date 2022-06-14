PORTNAME=	kdisplay
DISTVERSIONPREFIX=	${PORTNAME}@
DISTVERSION=	5.24.0
PORTREVISION=	1
CATEGORIES=	x11

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	74cab01dbddf.patch:-p1 # https://gitlab.com/kwinft/kdisplay/-/merge_requests/26

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	App and daemon for display managing
WWW=		https://gitlab.com/kwinft/kdisplay

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LGPL

LIB_DEPENDS=	libdisman.so:x11/disman
TEST_DEPENDS=	${qt-testlib_PORT:T}>0:${qt-testlib_PORT}

USES=		cmake:testing kde:5 qt:5
USE_GITLAB=	yes
USE_KDE=	ecm:build config coreaddons dbusaddons globalaccel i18n \
		kcmutils kdeclarative plasma-framework xmlgui
USE_LDCONFIG=	yes
USE_QT=		qmake:build buildtools:build core dbus declarative gui \
		sensors widgets
GL_ACCOUNT=	kwinft
GL_COMMIT=	a4dcebd297fded753579c7aef5a874617d274b7f
PLIST_SUB=	VERSION=${PORTVERSION}
LDFLAGS+=	-Wl,--as-needed # Qt5*, KF5*

.include <bsd.port.mk>
