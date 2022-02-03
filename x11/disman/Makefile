PORTNAME=	disman
DISTVERSIONPREFIX=	${PORTNAME}@
DISTVERSION=	0.524.0-beta.0
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Qt/C++ display management library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

TEST_DEPENDS=	${qt-testlib_PORT:T}>0:${qt-testlib_PORT}

USES=		cmake:testing kde:5 qt:5
USE_GITLAB=	yes
USE_KDE=	ecm_build coreaddons
USE_LDCONFIG=	yes
USE_QT=		qmake_build buildtools_build core dbus gui
GL_ACCOUNT=	kwinft
GL_COMMIT=	f30cc9df8202b63ee57b7fb709c57f2b28b251d7
PLIST_SUB=	VERSION=${PORTVERSION}
PLIST_SUB=	VERSION=0.523.90 # XXX beta override

OPTIONS_DEFINE=	WAYLAND X11
OPTIONS_DEFAULT=WAYLAND X11
OPTIONS_SUB=	yes

WAYLAND_LIB_DEPENDS=	libWraplandClient.so:graphics/wrapland
WAYLAND_USE=		KDE=wayland
WAYLAND_CMAKE_BOOL_OFF=	${KF5Wayland Wrapland:L:S/^/CMAKE_DISABLE_FIND_PACKAGE_/}

X11_USES=		xorg
X11_USE=		QT=x11extras XORG=xcb
X11_CMAKE_BOOL_OFF=	${Qt5X11Extras XCB:L:S/^/CMAKE_DISABLE_FIND_PACKAGE_/}

post-patch:
# Respect PREFIX for hwdata
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/backends/edid.cpp

.include <bsd.port.mk>
