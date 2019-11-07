# Created by: FURUSAWA,Kazuhisa <kazu@jp.freebsd.org>
# $FreeBSD$

PORTNAME=	lupe
PORTVERSION=	0.08c
CATEGORIES=	x11 accessibility
MASTER_SITES=	http://www2s.biglobe.ne.jp/~yav/soft/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time magnifying glass for X11

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		xorg
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lX11 -lXext -lm

PORTDOCS=	${PORTNAME}.doc
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

post-extract:
	@${LN} -sf ${PORTNAME}.man ${WRKSRC}/${PORTNAME}.1

do-build:
	(cd ${WRKSRC} \
		&& ${CC} ${CFLAGS} ${CPPFLAGS} -o ${PORTNAME} *.c ${LDFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.doc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
