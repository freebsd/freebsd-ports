PORTNAME=	scenefx
DISTVERSION=	0.4.1
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	04

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	wlroots scene API, but with eye candy!
WWW=		https://github.com/wlrfx/scenefx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.41:graphics/wayland-protocols
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libwayland-server.so:graphics/wayland \
		libwlroots-0.19.so:x11-toolkits/wlroots019 \

USES=		compiler:c11 meson pkgconfig xorg
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_XORG=	pixman
GH_ACCOUNT=	wlrfx
MESON_ARGS=	-Dexamples=false -Drenderers=${RENDERERS:ts,}
PLIST_SUB=	SUFFIX=-${DISTVERSION:R}

PORTSCOUT=	limit:^0\.4\.

OPTIONS_DEFINE=	OPENGL
OPTIONS_DEFAULT=OPENGL
OPTIONS_SLAVE=	OPENGL # XXX Remove after adding VULKAN

OPENGL_USES=		gl
OPENGL_USE=		GL=egl,gbm,glesv2
OPENGL_VARS=		RENDERERS+=gles2

.include <bsd.port.mk>
