PORTNAME=	hypridle
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	x11 wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	56f334cbe867.patch:-p1 # https://github.com/hyprwm/hypridle/issues/7
PATCHFILES+=	ea8588fefbe5.patch:-p1 # https://github.com/hyprwm/hypridle/pull/19

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Hyprland's idle daemon #'
WWW=		https://github.com/hyprwm/hypridle

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libsdbus-c++.so:devel/sdbus-cpp \
		libwayland-client.so:graphics/wayland

USES=		compiler:c++11-lib cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm
LDFLAGS+=	-Wl,--as-needed # sdbus-cpp deps
PLIST_FILES=	bin/${PORTNAME}

post-patch:
# Temporarily use ConsoleKit2 like sysutils/gnome-settings-daemon
	@${REINPLACE_CMD} -e 's,/login1,/ConsoleKit/Manager,' \
		-e 's,login1,ConsoleKit,' \
		-e 's,logind,consolekit2,' \
		-e 's,GetSession,&ByPID,' \
		-e 's,"auto",uint32_t{getpid()},' \
		${WRKSRC}/src/core/Hypridle.cpp

.include <bsd.port.mk>
