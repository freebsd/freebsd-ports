# New ports collection makefile for:	bbrun
# Date created:				3 August 2001
# Whom:					Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	bbrun
PORTVERSION=	1.6
CATEGORIES=	x11
MASTER_SITES=	http://www.darkops.net/bbrun/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Run box for Blackbox

USE_GETOPT_LONG=yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/bbrun
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bbrun ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
.endif

.include <bsd.port.mk>
