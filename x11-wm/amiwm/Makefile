# New ports collection Makefile for: amiwm-0.20pl28
# Date created: 13 November 1997
# Whom: Douglas Carmichael <dcarmich@mcs.com>
#
# $FreeBSD$
#

PORTNAME=	amiwm
PORTVERSION=	0.21.pl2
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/X11/wm/amiwm/
DISTNAME=	${PORTNAME}0.21pl2

MAINTAINER=	dcarmich@dcarmichael.net
COMMENT=	A window manager that makes your desktop look like an Amiga(TM)

GNU_CONFIGURE=	yes
USE_XORG=	x11 ice sm xext xmu
MAN1=		amiwm.1

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Copying documents to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	@${INSTALL_DATA} ${WRKSRC}/README.modules ${DOCSDIR}/README.modules
.endif

.include <bsd.port.mk>
