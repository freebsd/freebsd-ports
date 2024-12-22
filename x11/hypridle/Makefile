PORTNAME=	hypridle
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Hyprland's idle daemon #'
WWW=		https://github.com/hyprwm/hypridle

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libhyprutils.so:devel/hyprutils \
		libsdbus-c++.so:devel/sdbus-cpp \
		libwayland-client.so:graphics/wayland

USES=		compiler:c++11-lib cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm
LDFLAGS+=	-Wl,--as-needed # sdbus-cpp deps
PLIST_FILES=	bin/${PORTNAME} \
		lib/systemd/user/${PORTNAME}.service \
		share/hypr/${PORTNAME}.conf

post-patch:
# https://github.com/ConsoleKit2/ConsoleKit2/issues/150
# https://github.com/ConsoleKit2/ConsoleKit2/issues/151
	@${REINPLACE_CMD} -e 's,/login1,/ConsoleKit/Manager,' \
		-e 's,login1,ConsoleKit,' \
		-e 's,logind,consolekit2,' \
		-e 's,GetSession,&ByPID,' \
		-e 's,"auto",uint32_t{getpid()},' \
		${WRKSRC}/src/core/Hypridle.cpp

.include <bsd.port.mk>
