# New ports collection makefile for:	wxGTK
# Version required:	2.0.2
# Date created:		18 Jun 1999
# Whom:			Alexander Langer <alex@cichlids.com>
#
# $FreeBSD$
#

DISTNAME=	wxGTK-2.0.1
PKGNAME=	wxgtk-2.0.1
CATEGORIES= 	x11-toolkits
MASTER_SITES=	ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/source/
EXTRACT_SUFX=	.tgz

MAINTAINER= 	alex@cichlids.com

LIB_DEPENDS=	gtk10:${PORTSDIR}/x11-toolkits/gtk10:install

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OSTYPE="${OPSYS}"
USE_GMAKE=	yes
MAKE_ENV=	OSTYPE="${OPSYS}"

WRKSRC=		${WRKDIR}/wxGTK

post-install:
# There are two empty directories that make problems
# while deinstalling if installed as a .tgz-package.
	${TOUCH} ${PREFIX}/include/wx/motif/.placeholder
	${TOUCH} ${PREFIX}/include/wx/common/.placeholder

.include <bsd.port.mk>
