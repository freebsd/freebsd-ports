# New ports collection makefile for:   ion-devel
# Date created:        20 August 2003
# Whom:                anthony.ginepro@laposte.net
# Original ion port:   ricci@cs.utah.edu
#
# $FreeBSD$
#

PORTNAME=	ion-2
PORTVERSION=	20040407
CATEGORIES=	x11-wm
MASTER_SITES=	http://modeemi.fi/~tuomov/ion/dl/

MAINTAINER=	anthony.ginepro@laposte.net
COMMENT=	Ion is a tiling tabbed window manager

LIB_DEPENDS=	ltdl.4:${PORTSDIR}/devel/libltdl \
		lua.5:${PORTSDIR}/lang/lua

CONFLICTS=	ion-2002* ion-devel-*

USE_LIBTOOL_VER=15
USE_X_PREFIX=	yes
USE_GMAKE=	yes

MAN1=		ion.1 pwm.1
DOCSDIR=	share/doc/ion

# NO, I don't want to use configure but ion's author system.mk
do-configure:

.include <bsd.port.mk>
