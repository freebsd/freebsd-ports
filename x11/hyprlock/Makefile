PORTNAME=	hyprlock
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Hyprland's GPU-accelerated screen locking utility #'
WWW=		https://github.com/hyprwm/hyprlock

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	hyprwayland-scanner>=0.4.4:devel/hyprwayland-scanner \
		wayland-protocols>=1.35:graphics/wayland-protocols
LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libhyprutils.so:devel/hyprutils \
		libsdbus-c++.so:devel/sdbus-cpp \
		libhyprgraphics.so:graphics/hyprgraphics \
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
		etc/pam.d/${PORTNAME} \
		share/hypr/${PORTNAME}.conf

# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=282377
.if exists(/usr/lib/libc++.so)
LIB_DEPENDS+=	libdate-tz.so:devel/date
USES+=		localbase:ldflags

post-patch:	libcxx-post-patch
libcxx-post-patch:
	@${REINPLACE_CMD} '/_LIBCPP_VERSION/s/$$/ || defined(_LIBCPP_HAS_NO_TIME_ZONE_DATABASE)/' \
		${WRKSRC}/src/renderer/widgets/IWidget.cpp
.endif

.include <bsd.port.mk>
