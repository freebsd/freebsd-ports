PORTNAME=	bspwm
DISTVERSION=	0.9.10.20230829
PORTREVISION=	1
CATEGORIES=	x11-wm
PKGNAMESUFFIX=	-devel

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	Tiling window manager based on binary space partitioning
WWW=		https://github.com/baskerville/bspwm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms
RUN_DEPENDS=	sxhkd:x11/sxhkd

USES=		gmake localbase:ldflags xorg
USE_GITHUB=	yes
GH_ACCOUNT=	baskerville
GH_TAGNAME=	af3bd8b4351f4478fe0fe3cfd6c09e44cb108b4b
USE_XORG=	xcb

CONFLICTS_INSTALL=	bspwm

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DOCS EXAMPLES CONTRIB
OPTIONS_DEFAULT=	CONTRIB
OPTIONS_SUB=		yes
CONTRIB_DESC=		Install contrib (shell completions, etc.)

do-install:
	${MKDIR} ${STAGEDIR}${BINDIR} ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/bspc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bspwm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/bspc.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bspwm.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-CONTRIB-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${WRKSRC}/contrib/bash_completion \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/bspc
	${INSTALL_DATA} ${WRKSRC}/contrib/fish_completion \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/bspc.fish
	${INSTALL_DATA} ${WRKSRC}/contrib/zsh_completion \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_bspc
	${INSTALL_DATA} ${WRKSRC}/contrib/freedesktop/bspwm.desktop \
		${STAGEDIR}${PREFIX}/share/xsessions/bspwm.desktop

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
