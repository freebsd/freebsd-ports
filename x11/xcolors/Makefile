# New ports collection makefile for:	xcolors
# Version required:	R6 contrib
# Date created:		10 May 1995
# Whom:			asami
#
# $Id: Makefile,v 1.2 1995/10/02 08:11:03 asami Exp $
#

DISTNAME=	xcolors
PKGNAME=	xcolors-1.3
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.x.org/pub/R6untarred/contrib/programs/

# Note: do NOT create an md5 checksum for xcolors.tar.gz, it may
# change because of compression options on the ftp server.

MAINTAINER=	asami@FreeBSD.ORG

FETCH_DEPENDS=	ncftp2:${PORTSDIR}/net/ncftp2

WRKSRC=		${WRKDIR}/xcolors
USE_IMAKE=	yes

.include <bsd.port.mk>
