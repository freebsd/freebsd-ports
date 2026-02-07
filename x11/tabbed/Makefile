PORTNAME=	tabbed
DISTVERSION=	0.8
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	mp39590@gmail.com
COMMENT=	Tabbed frontend to Xembed-aware applications
WWW=		https://tools.suckless.org/tabbed

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		localbase:ldflags pkgconfig xorg
USE_XORG=	x11 xft xorgproto
MAKE_ARGS=	PREFIX="${PREFIX}" CC="${CC}"

PLIST_FILES=	bin/tabbed \
		bin/xembed \
		share/man/man1/tabbed.1.gz \
		share/man/man1/xembed.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

pre-everything::
	@${ECHO_MSG} "You can build tabbed with your own config.h using the TABBED_CONF knob:"
	@${ECHO_MSG} "make TABBED_CONF=/path/to/tabbed/config.h install clean"

post-extract:
.if defined(TABBED_CONF)
	@${ECHO_MSG} "creating config.h from ${TABBED_CONF}"
	@${CP} ${TABBED_CONF} ${WRKSRC}/config.h
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
