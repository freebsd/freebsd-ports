# New ports collection makefile for:    XFree86-contrib
# Version required:     3.3
# Date created:         7 November 1996
# Whom:                 asami
#
# $Id: Makefile,v 1.5 1997/07/17 15:12:59 max Exp $
#

DISTNAME=	XFree86-contrib-3.3.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3/source/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.3/source/ \
		ftp://ftp.ibp.fr/pub/X11/XFree86/XFree86-3.3/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.3/source/
DISTFILES=	X331contrib.tgz

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
