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

CONFLICTS=	xsel-conrad-[0-9]*
USE_BZIP2=	yes
USE_XORG=	xmu xaw xt xproto xkbfile
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lXt -lXaw -lX11 -lXmu
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	${PORTNAME}.html

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} xsel.c -o xsel ${LDFLAGS}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man ${MAN1PREFIX}/man/man1/${PORTNAME}.1
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
