# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	fbpager
PORTVERSION=	0.1.4
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.fluxbox.org/download/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Desktop pager for the Fluxbox window manager

DEPRECATED=	BRoken for more than 6 month
EXPIRATION_DATE=	2013-11-18

USE_XORG=	x11
GNU_CONFIGURE=	yes

BROKEN=		checksum mismatch

PLIST_FILES=	bin/fbpager
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
