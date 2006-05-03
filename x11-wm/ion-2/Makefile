# New ports collection makefile for:   ion-2
# Date created:        20 August 2003
# Whom:                anthony.ginepro@laposte.net
# Original ion port:   ricci@cs.utah.edu
#
# $FreeBSD$
#

PORTNAME=	ion-2
PORTVERSION=	20040729
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://modeemi.fi/~tuomov/ion/dl/

MAINTAINER=	anthony.ginepro@laposte.net
COMMENT=	Ion is a tiling tabbed window manager

LIB_DEPENDS=	lua.5:${PORTSDIR}/lang/lua50

CONFLICTS=	ion-2002* ion-devel-* pwm-*

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15 libltdl:15
USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ENV=	DEFINES="${IONDEFINES}"

.if !defined(WITH_MULTIBYTE)
IONDEFINES+=	-DCF_NO_MB_SUPPORT
.endif

MAN1=		ion.1 pwm.1
DOCSDIR=	share/doc/ion

# NO, I don't want to use configure but ion's author system.mk
do-configure:

.include <bsd.port.mk>
