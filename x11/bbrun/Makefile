# New ports collection makefile for:	bbrun
# Date created:				3 August 2001
# Whom:					Adam Weinberger
#
# $FreeBSD$
#

PORTNAME=	bbrun
PORTVERSION=	1.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/contrib/ \
		ftp://ftp.surfnet.nl/pub/os/Linux/distr/gentoo/distfiles/ \
		http://www.linuxtux.org/downloads/linux/bb/bbstuff/ \
		http://www.ibiblio.org/gentoo/distfiles/

MAINTAINER=	monkey@crackula.com

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
RUN_DEPENDS=	blackbox:${PORTSDIR}/x11-wm/blackbox

USE_X_PREFIX=	yes
USE_GTK=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/bbrun

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bbrun ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
.endif

.include <bsd.port.mk>
