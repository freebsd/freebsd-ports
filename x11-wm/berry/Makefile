PORTNAME=	berry
DISTVERSION=	0.1.12
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Byte-sized, Xlib-based window manager
WWW=		https://berrywm.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gmake pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	JLErvin
USE_XORG=	x11 xft xinerama

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/share/man \
		--prefix=${PREFIX}

PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}c \
		share/man/man1/${PORTNAME}.1.gz \
		share/man/man1/${PORTNAME}c.1.gz
PORTDOCS=	README.md
PORTEXAMPLES=	autostart sxhkdrc xephyr.sh

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's,va_copy(,__&,' \
		${WRKSRC}/utils.c
	@${REINPLACE_CMD} -e '/^#!/s,bash,sh,' \
		${WRKSRC}/examples/autostart \
		${WRKSRC}/examples/xephyr.sh

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
