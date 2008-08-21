# New ports collection makefile for:    fbpager
# Date created:                         25 Mar 2004
# Whom:                                 Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	fbpager
PORTVERSION=	0.1.4
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.fluxbox.org/download/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Desktop pager for the Fluxbox window manager

USE_XORG=	x11
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/fbpager
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
