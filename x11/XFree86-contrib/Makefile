# New ports collection makefile for:    XFree86-contrib
# Version required:     3.3.3
# Date created:         7 November 1996
# Whom:                 asami
#
# $Id: Makefile,v 1.12 1998/11/23 21:52:11 jmz Exp $
#

DISTNAME=	X333contrib
PKGNAME=	XFree86-contrib-3.3.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3.3/source/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.3.3/source/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-3.3.3/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.3.3/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmz@FreeBSD.ORG

# Define FORCE_PACKAGE from the command line if you want to override
# this and build a package
NO_PACKAGE=	"Binary package distributed by XFree86 already"
USE_IMAKE=	yes
DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/contrib
MAN1=		ico.1 listres.1 showfont.1 viewres.1 xbiff.1 xcalc.1 \
		xditview.1 xedit.1 xev.1 xeyes.1 xfontsel.1 xgc.1 xload.1 \
		xman.1 xmessage.1

.include <bsd.port.mk>
