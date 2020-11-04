# $FreeBSD$

PORTNAME=	berry
PORTVERSION=	0.1.7
CATEGORIES=	x11-wm

MAINTAINER=	vulcan@wired.sh
COMMENT=	Byte-sized, Xlib-based window manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	JLErvin
USE_XORG=	x11 xft xinerama

MAKE_ARGS=	CC="${CC}" \
		FREETYPEINC="${LOCALBASE}/include/freetype2" \
		MANPREFIX="${MANPREFIX}/man" \
		X11INC="${LOCALBASE}/include" \
		X11LIB="${LOCALBASE}/lib"

PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}c \
		man/man1/${PORTNAME}.1.gz \
		man/man1/${PORTNAME}c.1.gz
PORTDOCS=	README.md
PORTEXAMPLES=	autostart sxhkdrc xephyr.sh

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's,va_copy(,__&,' ${WRKSRC}/utils.c
	@${REINPLACE_CMD} -e '/^#!/s,bash,sh,' \
		${WRKSRC}/examples/autostart ${WRKSRC}/examples/xephyr.sh

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
