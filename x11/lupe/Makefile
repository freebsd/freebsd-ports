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

USE_XORG=	x11 xext
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lX11 -lXext -lm

MAN1=		${PORTNAME}.1
PORTDOCS=	${PORTNAME}.doc
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

post-extract:
	@${LN} -sf ${PORTNAME}.man ${WRKSRC}/${PORTNAME}.1

do-build:
	(cd ${WRKSRC} \
		&& ${CC} ${CFLAGS} ${CPPFLAGS} -o ${PORTNAME} *.c ${LDFLAGS})

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} ${PORTNAME}.1 ${MANPREFIX}/man/man1)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTNAME}.doc ${DOCSDIR})
.endif

.include <bsd.port.mk>
