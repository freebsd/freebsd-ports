# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i3lock
PORTVERSION=	2.10
CATEGORIES=	x11
MASTER_SITES=	http://i3wm.org/${PORTNAME}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Slightly improved screen locker based on slock

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-image.so:x11/xcb-util-image \
		libev.so:devel/libev \
		libxkbfile.so:x11/libxkbfile \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-util.so:x11/xcb-util

MAKE_ARGS=	PREFIX="${PREFIX}" X11LIB="${LOCALBASE}/lib" \
		X11INC="${LOCALBASE}/include" CC="${CC}" \
		MANDIR="${MANPREFIX}/man"

PLIST_FILES=	"@(,,4755) bin/i3lock" \
		man/man1/i3lock.1.gz

LDFLAGS+=	${ICONV_LIB}
USE_XORG=	x11 xcb xt xproto xext
USES=		gmake iconv pkgconfig tar:bzip2

PORTDOCS=	CHANGELOG README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|.*pam.d/i3lock.*|	$$(INSTALL)\
		-m 644 i3lock.1 $$(DESTDIR)$$(PREFIX)/man/man1|; \
		/pam.d/d' \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/i3lock

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
