# New ports collection makefile for:	bbrun
# Date created:				3 August 2001
# Whom:					Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	bbrun
PORTVERSION=	1.4
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.dwave.net/~jking/bbrun/

MAINTAINER=	adamw@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_XPM=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/bbrun

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bbrun ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
.endif

.include <bsd.port.mk>
