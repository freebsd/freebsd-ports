PORTNAME=	lxqt-session
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Session manager component for LXQt
WWW=		https://github.com/lxqt/lxqt-session/

LICENSE=	LGPL21+

BUILD_DEPENDS=	xdg-user-dirs-update:devel/xdg-user-dirs \
		qtxdg-mat:sysutils/qtxdg-tools

USES=		cmake compiler:c++20-lang kde:6 localbase:ldflags perl5 pkgconfig \
		lxqt:2 qt:6 tar:xz xorg gnome
USE_QT=		tools:build base:run svg
USE_KDE=	layer-shell-qt windowsystem
USE_PERL5=	build
USE_XORG=	x11 ice sm xcb xext
USE_GNOME=	glib20
USE_LXQT=	buildtools2 lxqt qt6xdg

CMAKE_OFF=	WITH_LIBUDEV

post-patch:
	@${REINPLACE_CMD} -e 's|\@PREDEF_XDG_CONFIG_DIRS\@|\@PREDEF_XDG_CONFIG_DIRS\@:\${LOCALBASE}/share|g' ${WRKSRC}/startlxqt.in

.include <bsd.port.mk>
