PORTNAME=	i3lock-color
DISTVERSION=	2.13.c.4
PORTREVISION=	3
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

USES=		autoreconf gmake gnome iconv jpeg localbase pkgconfig tar:bzip2 xorg
USE_CSTD=	c99
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	Raymo111
USE_GNOME=	cairo
USE_XORG=	x11 xcb xext xinerama xorgproto xrandr xt

GNU_CONFIGURE=	yes

MAKE_ARGS=	PREFIX="${PREFIX}" X11LIB="${LOCALBASE}/lib" \
		X11INC="${LOCALBASE}/include" CC="${CC}"

LDFLAGS+=	${ICONV_LIB}

CONFLICTS_INSTALL=	i3lock

PLIST_FILES=	bin/i3lock \
		etc/pam.d/i3lock \
		man/man1/i3lock.1.gz

OPTIONS_DEFINE=	DOCS

DOC_FILES=	CHANGELOG README.md
DOCS_PLIST_FILES=	${DOC_FILES:S|^|${DOCSDIR_REL}/|}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/i3lock
	@${RM} ${STAGEDIR}${PREFIX}/etc/pam.d/i3lock
	@${LN} -s ${LOCALBASE}/etc/pam.d/unix-selfauth \
		${STAGEDIR}${PREFIX}/etc/pam.d/i3lock

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
