# New ports collection makefile for:	idesk
# Date created:		16 February 2003
# Whom:			Sascha Holzleiter <sascha@root-login.org>
#
# $FreeBSD$
#

PORTNAME=	idesk
PORTVERSION=	0.3.5
CATEGORIES=	x11
MASTER_SITES=	http://linuxhelp.hn.org/

MAINTAINER=	sascha@root-login.org
COMMENT=	Place launch icons directly on your desktop

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib

CXXFLAGS+=	`imlib-config --cflags` `freetype-config --cflags`
MAKE_ARGS=	cc="${CXX}" cflags="${CXXFLAGS}"

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/idesk ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
