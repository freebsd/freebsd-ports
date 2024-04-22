PORTNAME=	gxkb
PORTVERSION=	0.9.5
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}
# RU and BY flags were removed as of version 0.9.4 so we need two distfiles
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-0.9.3${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	X11 keyboard layout indicator and switcher
WWW=		https://zen-tools.github.io/gxkb/

LICENSE=	GPLv2

LIB_DEPENDS=	libxklavier.so:x11/libxklavier

USES=		gnome pkgconfig
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_GNOME=	gdkpixbuf2 glib20

PORTDOCS=	AUTHORS NEWS

OPTIONS_DEFINE=	DOCS GTK2
GTK2_DESC=	Build against GTK version 2, not 3

GTK2_EXTRA_PATCHES=	${FILESDIR}/extra-patch-gtk2
GTK2_LIB_DEPENDS=	libwnck-1.so:x11-toolkits/libwnck
GTK2_LIB_DEPENDS_OFF=	libwnck-3.so:x11-toolkits/libwnck3
GTK2_USES=		autoreconf
GTK2_USE=		GNOME=gtk20
GTK2_USE_OFF=		GNOME=gtk30

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e '/^doc_DATA/s, C[^ ]*,,g' \
		${WRKSRC}/doc/Makefile.[ai][mn]

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s, doc,,' ${WRKSRC}/Makefile.in

post-install:
.for c in by ru
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-0.9.3/data/flags/${c}.png \
		${STAGEDIR}${DATADIR}/flags
.endfor

.include <bsd.port.mk>
