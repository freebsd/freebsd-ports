# New ports collection makefile for:    wxGTK
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wxgtk
PORTVERSION=	2.1.11
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/source/ \
		http://www.nectar.com/distfiles/
DISTNAME=	wxGTK-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nectar@FreeBSD.ORG

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_NEWGCC=	yes

WRKSRC=		${WRKDIR}/wxGTK

CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"

post-install:
	${SETENV} OBJFORMAT="${PORTOBJFORMAT}" ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
