# Created by: J Han <hjh@photino.com>
# $FreeBSD$

PORTNAME=	lwm
PORTVERSION=	1.2.3
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.jfc.org.uk/files/lwm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight window manager

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	DOCS

USES=		pkgconfig
USE_XORG=	sm x11 xext
MAKEFILE=	no_xmkmf_makefile
MAKE_ARGS=	LDFLAGS="${LDFLAGS}"

CFLAGS+=	`pkg-config --cflags sm x11 xext ice` -DSHAPE
LDFLAGS+=	`pkg-config --libs sm x11 xext ice`

MAN1=		${PORTNAME}.1
PORTDOCS=	AUTHORS BUGS ChangeLog README TODO
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

post-patch:
	@${LN} -sf ${PORTNAME}.man ${WRKSRC}/${PORTNAME}.1

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} ${PORTNAME}.1 ${MANPREFIX}/man/man1)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
