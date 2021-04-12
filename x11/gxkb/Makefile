# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	gxkb
PORTVERSION=	0.8.2
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	X11 keyboard layout indicator and switcher

LICENSE=	GPLv2

LIB_DEPENDS=	libxklavier.so:x11/libxklavier

USES=		gnome pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gdkpixbuf2 glib20

PORTSCOUT=	skipv:0.9.0	# same as 0.8.2, but GTK3 is the default

PORTDOCS=	AUTHORS NEWS

OPTIONS_DEFINE=	DOCS GTK3
GTK3_DESC=	Build against GTK version 3, not 2

GTK3_EXTRA_PATCHES=	${FILESDIR}/extra-patch-gtk3
GTK3_LIB_DEPENDS=	libwnck-3.so:x11-toolkits/libwnck3
GTK3_LIB_DEPENDS_OFF=	libwnck-1.so:x11-toolkits/libwnck
GTK3_USES=		autoreconf
GTK3_USE=		GNOME=gtk30
GTK3_USE_OFF=		GNOME=gtk20

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e '/^doc_DATA/s, C[^ ]*,,g' \
		${WRKSRC}/doc/Makefile.[ai][mn]

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s, doc,,' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
