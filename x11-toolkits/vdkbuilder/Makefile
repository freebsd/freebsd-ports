# New ports collection makefile for:   vdkbuilder
# Version required:    1.0.6
# Date created:        29 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	vdkbuilder-1.0.6
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.programmers.net/artic/Motta/vdk/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	vdk.1:${PORTSDIR}/x11-toolkits/vdk

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_NEWGCC=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
