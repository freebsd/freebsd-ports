# New ports collection makefile for:	xrsi
# Date created:		2007-03-17
# Whom:			Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	xrsi
PORTVERSION=	0.9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xrsi

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	A minimalist break enforcer for linux/unix for the prevention of RSI

USE_XLIB=	yes
PLIST_FILES=	bin/xrsi
PORTDOCS=	Readme Licence

do-build:
	${CC} ${CFLAGS} -I${X11BASE}/include -L${X11BASE}/lib -lX11 -o ${WRKSRC}/xrsi ${WRKSRC}/xrsi.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrsi ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme  ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/Licence ${DOCSDIR}/
.endif

.include <bsd.port.mk>
