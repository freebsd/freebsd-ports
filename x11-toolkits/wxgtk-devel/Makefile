# New ports collection makefile for:    wxGTK
# Version required:     		2.1.0b9
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

DISTNAME=	wxGTK-2.1.0-b9
PKGNAME=	wxgtk-2.1.0b9
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/source/ \
		http://www.nectar.com/distfiles/
EXTRACT_SUFX=   .tgz

MAINTAINER=	nectar@FreeBSD.ORG

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_NEWGCC=	yes

WRKSRC=         ${WRKDIR}/wxGTK

CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"

post-install:
	${SETENV} OBJFORMAT="${PORTOBJFORMAT}" ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
