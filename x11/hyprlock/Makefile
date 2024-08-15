PORTNAME=	hyprlock
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Hyprland's GPU-accelerated screen locking utility #'
WWW=		https://github.com/hyprwm/hyprlock

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libhyprutils.so:devel/hyprutils \
		libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland \
		libwebp.so:graphics/webp \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	unix-selfauth-helper>0:security/unix-selfauth-helper

USES=		cmake compiler:c++11-lib gl gnome jpeg pkgconfig
USE_GITHUB=	yes
USE_GL=		egl gbm
USE_GNOME=	cairo pango
GH_ACCOUNT=	hyprwm
LDFLAGS+=	-Wl,--as-needed # pango deps
PLIST_FILES=	bin/${PORTNAME} \
		etc/pam.d/${PORTNAME}

# XXX Drop after FreeBSD 14.0 EOL around 2024-10-01
.if exists(/usr/lib/libc++.so) && !exists(/usr/include/c++/v1/__format/write_escaped.h)
CXXFLAGS+=	-fexperimental-library
.endif

# XXX Drop after FreeBSD 13.3 EOL around 2025-07-01
.if exists(/usr/lib/libc++.so) && !exists(/usr/include/c++/v1/__chrono/time_zone.h)
LIB_DEPENDS+=	libdate-tz.so:devel/date
USES+=		localbase:ldflags
.endif

.include <bsd.port.mk>
