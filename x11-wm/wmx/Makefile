# Created by: Stefan Zehl <sec@42.org>
# $FreeBSD$

PORTNAME=	wmx
PORTVERSION=	8
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.all-day-breakfast.com/wmx/

MAINTAINER=	kwhite@site.uottawa.ca
COMMENT=	Simple window manager based on wm2

USES=		pkgconfig xorg
GNU_CONFIGURE=	yes
USE_XORG=	ice sm x11 xcomposite xext xft xpm

PLIST_FILES=	bin/wmx
PORTDOCS=	README README.contrib

OPTIONS_DEFINE=	ALT_L XTERM DOCS
OPTIONS_DEFAULT=	XTERM

ALT_L_DESC=	Use ALT_L key for ALT function instead of Windows_L
XTERM_DESC=	Use xterm(1) as default NEW window command

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MXTERM}
	@${REINPLACE_CMD} -e '/CONFIG_NEW_WINDOW_COMMAND/ \
		s/x-terminal-emulator/xterm/' ${WRKSRC}/Config.h
.endif
.if ${PORT_OPTIONS:MALT_L}
	@${REINPLACE_CMD} -e '/CONFIG_ALT_KEY/s/XK_Super_L/XK_Alt_L/' \
		${WRKSRC}/Config.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmx ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
