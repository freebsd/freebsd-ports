PORTNAME=	owe
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.7
CATEGORIES=	x11 wayland

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	High-performance wallpaper engine for Omarchy (video, GIF, stills)
WWW=		https://github.com/omacom/owe

LICENSE=	MIT

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols \
		wayland-scanner:graphics/wayland
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libbasu.so:devel/basu \
		libepoxy.so:graphics/libepoxy \
		libmpv.so:multimedia/mpv \
		libwayland-client.so:graphics/wayland
RUN_DEPENDS=	bash:shells/bash \
		ffmpeg:multimedia/ffmpeg \
		socat:net/socat

USES=		gl meson pkgconfig python:test shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	omacom
USE_GL=		egl
SHEBANG_FILES=	hooks/owe-idle hooks/theme-set.d/10-owe-sync

TEST_TARGET=	test

PLIST_FILES=	${DATADIR_REL}/10-owe-sync \
		bin/owe \
		bin/owe-idle \
		bin/owe-render \
		bin/owed

PORTEXAMPLES=	config.toml

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hooks/owe-idle ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/hooks/theme-set.d/10-owe-sync \
		${STAGEDIR}${DATADIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config/config.toml ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
