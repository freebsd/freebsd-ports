# New ports collection makefile for:	xcolors
# Version required:	R6 contrib
# Date created:		10 May 1995
# Whom:			asami
#
# $Id: Makefile,v 1.8 1995/04/22 11:59:12 asami Exp $
#

DISTNAME=	xcolors
PKGNAME=	xcolors-1.3
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.x.org/pub/R6untarred/contrib/programs/

MAINTAINER=	asami@FreeBSD.ORG

USE_IMAKE=	yes

# Note: do NOT create an md5 checksum for xcolors.tar.gz, it may
# change because of compression options on the ftp server.

FTP_SITE=	ftp.x.org
FTP_DIR=	/pub/R6untarred/contrib/programs/

.if !defined(MASTER_SITE_OVERRIDE)
pre-fetch:
	@if [ ! -d ${DISTDIR} ]; then mkdir -p ${DISTDIR}; fi
	@(cd ${DISTDIR}; \
	  if [ ! -f ${DISTFILES} ]; then \
	    (sleep 5; echo "cd ${FTP_DIR}"; echo "get ${DISTFILES}") | ${NCFTP} ${NCFTPFLAGS} ${FTP_SITE}; \
	  fi \
	)
.endif

.include <bsd.port.mk>
