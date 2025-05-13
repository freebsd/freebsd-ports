PORTNAME=	gxkb
PORTVERSION=	0.9.6
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	X11 keyboard layout indicator and switcher
WWW=		https://zen-tools.github.io/gxkb/

LICENSE=	GPLv2

LIB_DEPENDS=	libxklavier.so:x11/libxklavier
RUN_DEPENDS=	${_FLAGS_DIR}/epo.png:misc/flag-icons@${_FLAGS_FLAVOR}

USES=		gnome pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gdkpixbuf glib20

PORTDOCS=	AUTHORS NEWS

OPTIONS_DEFINE=	DOCS GTK2
OPTIONS_DEFAULT=	ROUNDED
OPTIONS_SINGLE=	FLAGS
OPTIONS_SINGLE_FLAGS=	BORDERED PLAIN ROUNDED

FLAGS_DESC=	Preferred flag decorations
BORDERED_DESC=	Thin black border
PLAIN_DESC=	Plain (undecorated)
ROUNDED_DESC=	Rounded corners
GTK2_DESC=	Build against GTK version 2, not 3

GTK2_EXTRA_PATCHES=	${FILESDIR}/extra-patch-gtk2
GTK2_LIB_DEPENDS=	libwnck-1.so:x11-toolkits/libwnck
GTK2_LIB_DEPENDS_OFF=	libwnck-3.so:x11-toolkits/libwnck3
GTK2_USES=		autoreconf
GTK2_USE=		GNOME=gtk20
GTK2_USE_OFF=		GNOME=gtk30

_FLAGS_DIR=	${LOCALBASE}/share/icons/flag-icons/${_FLAGS_FLAVOR}/21x16
_FLAGS_FLAVOR=	${PORT_OPTIONS:${OPTIONS_DEFINE:S,^,N,:ts:}:tl}

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = flags/d' \
		${WRKSRC}/data/Makefile.[ai][mn]
	@${REINPLACE_CMD} -e 's,$$(datadir)/gxkb/flags,${_FLAGS_DIR},' \
		${WRKSRC}/src/Makefile.[ai][mn]

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e '/^doc_DATA/s, C[^ ]*,,g' \
		${WRKSRC}/doc/Makefile.[ai][mn]

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s, doc,,' \
		${WRKSRC}/Makefile.[ai][mn]

.include <bsd.port.mk>
