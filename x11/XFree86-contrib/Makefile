# New ports collection makefile for:    XFree86-contrib
# Version required:     3.3
# Date created:         7 November 1996
# Whom:                 asami
#
# $Id: Makefile,v 1.9 1998/04/13 14:32:13 markm Exp $
#

DISTNAME=	X332contrib
PKGNAME=	XFree86-contrib-3.3.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3.2/source/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.3.2/source/ \
		ftp://ftp.ibp.fr/pub/X11/XFree86/XFree86-3.3.2/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.3.2/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmz@FreeBSD.ORG

# Define FORCE_PACKAGE from the command line if you want to override
# this and build a package
NO_PACKAGE=	"Binary package distributed by XFree86 already"
USE_IMAKE=	yes
DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/contrib

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
