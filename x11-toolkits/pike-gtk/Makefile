# New ports collection makefile for:	pike-gtk
# Date created:		June 29, 1999
# Whom:	      		Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pike-gtk
PORTVERSION= 	1.1.3
CATEGORIES=	x11-toolkits lang
MASTER_SITES=	http://pike-community.org/sites/pigtk/download/
DISTNAME=	pigtk_${PORTVERSION}

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
