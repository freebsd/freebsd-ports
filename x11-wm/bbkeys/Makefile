# New ports collection makefile for: bbkeys
# Date created:        17 June 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	bbkeys
PORTVERSION=	0.8.5
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A keygrabber for the Blackbox window manager

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		bbkeys.1
MAN5=		bbkeysrc.5 bbkeys.bb.5

pre-patch:
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's@doc/bbkeys@share/doc/bbkeys@g' \
		${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -E 's|^docdir|#|; s|^doc_DATA|#|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
