PORTNAME=	i3lock-color
DISTVERSION=	2.13.c.5
CATEGORIES=	x11

MAINTAINER=	fjachuf@gmail.com
COMMENT=	Enhanced i3lock with higher capacity
WWW=		https://github.com/Raymo111/i3lock-color

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libev.so:devel/libev \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-util.so:x11/xcb-util \
		libxcb-xrm.so:x11/xcb-util-xrm \
		libxkbcommon.so:x11/libxkbcommon \
		libxkbfile.so:x11/libxkbfile
RUN_DEPENDS=	unix-selfauth-helper>0:security/unix-selfauth-helper

USES=		autoreconf gmake gnome iconv jpeg localbase pkgconfig tar:bzip2 \
		xorg
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	Raymo111
USE_GNOME=	cairo
USE_XORG=	x11 xcb xext xinerama xorgproto xrandr xt

GNU_CONFIGURE=	yes

MAKE_ARGS=	CC="${CC}" \
		PREFIX="${PREFIX}" \
		X11INC="${LOCALBASE}/include" \
		X11LIB="${LOCALBASE}/lib"

LDFLAGS+=	${ICONV_LIB}

CONFLICTS_INSTALL=	i3lock

PLIST_FILES=	bin/i3lock \
		etc/pam.d/i3lock \
		share/man/man1/i3lock.1.gz

OPTIONS_DEFINE=		BASH DOCS ZSH
OPTIONS_DEFAULT=	BASH ZSH

BASH_PLIST_FILES=	share/bash-completion/completions/i3lock
DOCS_PLIST_FILES=	${DOC_FILES:S|^|${DOCSDIR_REL}/|}
ZSH_PLIST_FILES=	share/zsh/site-functions/_i3lock

DOC_FILES=	CHANGELOG README.md

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/etc/pam.d/i3lock
	@${LN} -s ${LOCALBASE}/etc/pam.d/unix-selfauth \
		${STAGEDIR}${PREFIX}/etc/pam.d/i3lock

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA}	${WRKSRC}/i3lock-bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/i3lock

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-ZSH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA}	${WRKSRC}/i3lock-zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_i3lock

.include <bsd.port.mk>
