# New ports collection makefile for:	pike-gtk
# Version required:	1.1.3
# Date created:		June 29, 1999
# Whom:	      		Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

DISTNAME=	pigtk_1.1.3
PKGNAME=	pike-gtk-1.1.3
CATEGORIES=	x11-toolkits lang
MASTER_SITES=	http://pike-community.org/sites/pigtk/download/

MAINTAINER=	ijliao@csie.nctu.edu.tw

BUILD_DEPENDS=	pike:${PORTSDIR}/lang/pike
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config

# To delete "-Wl,-E" from options for ld.
# (The options are created by gtk12-config.)
post-configure:
	cd ${WRKSRC} ; ${PATCH} < ${FILESDIR}/patch-Makefile

.include <bsd.port.mk>
