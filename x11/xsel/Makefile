# Created by: ijliao
# $FreeBSD$

PORTNAME=	xsel
PORTVERSION=	0.04.1
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	CENKES
#http://www.niksula.cs.hut.fi/~vherva/xsel/xsel.{c,man}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Access X selection from command line

BROKEN=		No public distfiles

CONFLICTS=	xsel-conrad-[0-9]*
USES=	tar:bzip2
USE_XORG=	xmu xaw xt xproto xkbfile
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lXt -lXaw -lX11 -lXmu
PLIST_FILES=	bin/${PORTNAME} man/man1/xsel.1.gz
PORTDOCS=	${PORTNAME}.html

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} xsel.c -o xsel ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man ${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}.1
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
