# New ports collection makefile for:	lwm
# Date created:		17 March 1998
# Whom:			J Han <hjh@photino.com>
#
# $FreeBSD$
#

PORTNAME=	lwm
PORTVERSION=	1.2.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.jfc.org.uk/files/lwm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lightweight window manager

USE_XORG=	sm x11 xext
MAKEFILE=	no_xmkmf_makefile
MAKE_ARGS=	LDFLAGS="${LDFLAGS}"

MAN1=		${PORTNAME}.1
PORTDOCS=	AUTHORS BUGS ChangeLog README TODO
PLIST_FILES=	bin/${PORTNAME}

CFLAGS+=	`pkg-config --cflags sm x11 xext` -DSHAPE
LDFLAGS=	`pkg-config --libs sm x11 xext`

post-patch:
	@${LN} -sf ${PORTNAME}.man ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
