PORTNAME=	disman
DISTVERSIONPREFIX=	${PORTNAME}@
DISTVERSION=	0.524.0
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
GL_COMMIT=	a8fc81af423ab14513c7096b405cec3f58943495
PLIST_SUB=	VERSION=${PORTVERSION}

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
