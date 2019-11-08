# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gxkb
PORTVERSION=	0.8.1
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	X11 keyboard layout indicator and switcher

LICENSE=	GPLv2

LIB_DEPENDS=	libxklavier.so:x11/libxklavier \
		libwnck-1.so:x11-toolkits/libwnck

USES=		gnome pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gdkpixbuf2 glib20 gtk20

PORTDOCS=	AUTHORS NEWS

OPTIONS_DEFINE=	DOCS

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e '/^doc_DATA/s, C[^ ]*,,g' \
		${WRKSRC}/doc/Makefile.in

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s, doc,,' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
