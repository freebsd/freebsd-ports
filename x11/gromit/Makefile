# New ports collection makefile for:	gromit
# Date Created:				03 Mar 2003
# Whom:					Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	gromit
PORTVERSION=	20041213
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.home.unix-ag.org/simon/gromit/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	"GRaphics Over Miscellaneous Objects (Gromit)"

USE_X_PREFIX=	yes
USE_GNOME=	gtk20

DOCS=		AUTHORS ChangeLog README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gromit ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA}   ${WRKSRC}/gromitrc       ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
