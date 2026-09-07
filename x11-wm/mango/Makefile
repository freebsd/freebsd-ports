PORTNAME=	mango
DISTVERSION=	0.16.3
PORTREVISION=	0
CATEGORIES=	x11-wm

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Lightweight, high-performance Wayland compositor built on dwl
WWW=		https://mangowm.github.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	hwdata>=0.399:misc/hwdata \
		wayland-protocols>=1.24:graphics/wayland-protocols
LIB_DEPENDS=	libcjson.so:devel/libcjson \
		libinput.so:x11/libinput \
		libpcre2-8.so:devel/pcre2 \
		libpixman-1.so:x11/pixman \
		libscenefx-0.5.so:x11-toolkits/scenefx05 \
		libwayland-server.so:graphics/wayland \
		libwlroots-0.20.so:x11-toolkits/wlroots020 \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	hwdata>=0.399:misc/hwdata \
		Xwayland:x11-servers/xwayland

USES=		gnome meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	mangowm
USE_GNOME=	cairo glib20 pango

MESON_ARGS=	-Dsysconfdir=${PREFIX}/etc

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E -e "s|(assets/(config.conf))|\1', rename : '\2.sample|1" \
		${WRKSRC}/meson.build

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
