# New ports collection makefile for:    XFree86-contrib
# Version required:     3.2
# Date created:         7 November 1996
# Whom:                 asami
#
# $Id: Makefile,v 1.1.1.1 1996/11/09 02:04:56 asami Exp $
#

DISTNAME=	XFree86-contrib-3.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.2/source/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.2/source/ \
		ftp://ftp.ibp.fr/pub/X11/XFree86/XFree86-3.2/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.2/source/
DISTFILES=	X32contrib.tgz

MAINTAINER=	jmz@FreeBSD.ORG

# Define FORCE_PACKAGE from the command line if you want to override
# this and build a package
NO_PACKAGE=	yes
USE_IMAKE=	yes
DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/contrib

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
