# New ports collection makefile for:    wxGTK
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wxgtk
PORTVERSION= 	2.1.16
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/source/ \
		http://netfx-2000.linux.tucows.com/files/x11/dev/ \
		http://linuxberg.is.co.za/files/x11/dev/ \
		http://cyberec.linux.tucows.com/files/x11/dev/ \
		http://gil.linux.tucows.com/files/x11/dev/ \
		http://cyberbeach.linux.tucows.com/files/x11/dev/ \
		http://bonn.linux.tucows.com/files/x11/dev/ \
		http://matrix.linux.tucows.com/files/x11/dev/
DISTNAME=	wxGTK-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nectar@FreeBSD.ORG

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
INSTALL_SHLIBS=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_NEWGCC=	yes

WRKSRC=		${WRKDIR}/wxGTK

CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"

.include <bsd.port.mk>
