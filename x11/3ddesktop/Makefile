# New ports collection makefile for:	3ddesktop
# Date created:				12 June 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		3ddesktop
PORTVERSION=		0.2.5
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	desk3d

MAINTAINER=		adamw@FreeBSD.org
COMMENT=		3D Virtual Desktop Switcher

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes
USE_GETOPT_LONG=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README README.windowmanagers
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
