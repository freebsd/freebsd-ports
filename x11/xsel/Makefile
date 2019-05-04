# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xsel
PORTVERSION=	0.04.1
PORTREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://BSDforge.com/projects/source/x11/xsel/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Access X11 selection buffer from command line

LICENSE=	MIT

DEPRECATED=		Abandonware; use x11/xsel-conrad instead
EXPIRATION_DATE=	2019-05-08

CONFLICTS_INSTALL=	xsel-conrad-[0-9]*

USES=		tar:bzip2
USE_XORG=	xmu xaw xt xorgproto xkbfile

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lXt -lXaw -lX11 -lXmu

PLIST_FILES=	bin/${PORTNAME} man/man1/xsel.1.gz
PORTDOCS=	${PORTNAME}.html

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} xsel.c -o xsel ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man \
		${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}.1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
