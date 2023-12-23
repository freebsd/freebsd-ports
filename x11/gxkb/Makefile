PORTNAME=	gxkb
PORTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	X11 keyboard layout indicator and switcher
WWW=		https://zen-tools.github.io/gxkb/

LICENSE=	GPLv2

LIB_DEPENDS=	libxklavier.so:x11/libxklavier

USES=		gnome pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gdkpixbuf2 glib20

PORTDOCS=	AUTHORS NEWS

PORTSCOUT=	skipv:0.9.4	# identical to 0.9.3 but RU and BY flags removed

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

.include <bsd.port.mk>
