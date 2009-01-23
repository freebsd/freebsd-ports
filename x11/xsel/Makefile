# Ports collection makefile for:	xsel
# Date created:			Jan 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

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
LDFLAGS=	-L${LOCALBASE}/lib -lXt -lXaw
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	${PORTNAME}.html

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} xsel.c -o xsel ${LDFLAGS}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man ${MAN1PREFIX}/man/man1/${PORTNAME}.1
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
