PORTNAME=	lxqt-wayland-session
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Files needed for the LXQt Wayland Session
WWW=		https://github.com/lxqt/lxqt-wayland-session/

LICENSE=	LGPL21+

BUILD_DEPENDS=	xdg-user-dirs-update:devel/xdg-user-dirs \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
RUN_DEPENDS=	lxqt-session>=${PORTVERSION}:x11-wm/lxqt-session \
		bash:shells/bash

USES=		cmake compiler:c++20-lang gl localbase:ldflags perl5 pkgconfig \
		lxqt:2 shebangfix tar:xz xorg
USE_GL=		gl
USE_PERL5=	build
USE_XORG=	ice sm xcb xext
USE_LXQT=	buildtools2 lxqt

SHEBANG_FILES=	lxqt-qdbus.in

.include <bsd.port.mk>
