# New ports collection makefile for:	xcolors
# Version required:	R6 contrib
# Date created:		10 May 1995
# Whom:			asami
#
# $Id: Makefile,v 1.1.1.1 1995/05/10 09:53:40 asami Exp $
#

DISTNAME=	xcolors
PKGNAME=	xcolors-1.3
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.x.org/pub/R6untarred/contrib/programs/

# Note: do NOT create an md5 checksum for xcolors.tar.gz, it may
# change because of compression options on the ftp server.

MAINTAINER=	asami@FreeBSD.ORG

FETCH_DEPENDS=	ncftp2:${PORTSDIR}/net/ncftp2

WRKSRC=		${WRKDIR}/pub/R6untarred/contrib/programs/xcolors
NCFTP=		ncftp2
NCFTPFLAGS=
USE_IMAKE=	yes

.include <bsd.port.mk>
