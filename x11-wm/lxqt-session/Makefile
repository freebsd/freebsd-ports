PORTNAME=	lxqt-session
PORTVERSION=	1.3.0
CATEGORIES=	x11-wm
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Session manager component for LXQt
WWW=		https://github.com/lxqt/lxqt-session/

LICENSE=	LGPL21+

BUILD_DEPENDS=	xdg-user-dirs-update:devel/xdg-user-dirs \
		qtxdg-mat:sysutils/qtxdg-tools

USES=	cmake compiler:c++14-lang kde:5 lxqt qt:5 \
	perl5 pkgconfig tar:xz xorg gnome
USE_PERL5=	build
USE_QT=	buildtools:build qmake:build core dbus gui linguisttools \
	svg widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt qtxdg
USE_XORG=	x11 ice sm xcb xext
USE_GNOME=	glib20

CMAKE_OFF=	WITH_LIBUDEV
post-patch:
	@${REINPLACE_CMD} -e 's|\@PREDEF_XDG_CONFIG_DIRS\@|\@PREDEF_XDG_CONFIG_DIRS\@:\${LOCALBASE}/share|g' ${WRKSRC}/startlxqt.in

.include <bsd.port.mk>
