# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-session
PORTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Session manager component for LXQt

LICENSE=	LGPL21+

BUILD_DEPENDS=	xdg-user-dirs-update:devel/xdg-user-dirs

USES=	cmake compiler:c++14-lang kde:5 lxqt qt:5 \
	pkgconfig tar:xz xorg
USE_QT=	buildtools_build qmake_build core dbus gui linguisttools \
	svg widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt qtxdg
USE_XORG=	x11 ice sm xcb xext

CMAKE_OFF=	WITH_LIBUDEV
post-patch:
	@${REINPLACE_CMD} -e 's|\@PREDEF_XDG_CONFIG_DIRS\@|\@PREDEF_XDG_CONFIG_DIRS\@:\${LOCALBASE}/share|g' ${WRKSRC}/startlxqt.in

.include <bsd.port.mk>
