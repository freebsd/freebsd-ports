# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	bspwm
PORTVERSION=	0.9.6
CATEGORIES=	x11-wm

MAINTAINER=	o.hushchenkov@gmail.com
COMMENT=	Tiling window manager based on binary space partitioning

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms
RUN_DEPENDS=	sxhkd:x11/sxhkd

USES=		gmake localbase:ldflags

USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	baskerville

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES CONTRIB
OPTIONS_SUB=	yes
CONTRIB_DESC=	Install contrib (shell completions, etc.)

do-install:
	${MKDIR} ${STAGEDIR}${BINDIR} ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/bspc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bspwm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/bspc.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bspwm.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

post-install-CONTRIB-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${WRKSRC}/contrib/bash_completion ${STAGEDIR}${PREFIX}/share/bash-completion/completions/bspc
	${INSTALL_DATA} ${WRKSRC}/contrib/fish_completion ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/bspc.fish
	${INSTALL_DATA} ${WRKSRC}/contrib/zsh_completion ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_bspc
	${INSTALL_DATA} ${WRKSRC}/contrib/freedesktop/bspwm.desktop ${STAGEDIR}${PREFIX}/share/xsessions/bspwm.desktop

.include <bsd.port.mk>
