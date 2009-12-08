# New ports collection makefile for:   ion-2
# Date created:        20 August 2003
# Whom:                anthony.ginepro@laposte.net
# Original ion port:   ricci@cs.utah.edu
#
# $FreeBSD$
#

PORTNAME=	ion-2
PORTVERSION=	20040729
PORTREVISION=	5
CATEGORIES=	x11-wm
MASTER_SITES=	http://modeemi.fi/~tuomov/dl/archives/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tiling tabbed window manager

BROKEN=		Does not build with new libltdl 2.2
DEPRECATED=	has been broken for 4 months
EXPIRATION_DATE=2010-01-08

CONFLICTS=	ion-2002* ion-devel-* pwm-*

USE_XORG=	x11 xext xinerama
USE_AUTOTOOLS=	libtool:22 libltdl:22
USE_LUA=	5.0
USE_GMAKE=	yes
MAKE_ENV=	DEFINES="${IONDEFINES}"
GNU_CONFIGURE=	yes

.if !defined(WITH_MULTIBYTE)
IONDEFINES+=	-DCF_NO_MB_SUPPORT
.endif

MAN1=		ion.1 pwm.1
DOCSDIR=	share/doc/ion

# NO, I don't want to use configure but ion's author system.mk
do-configure:

.include <bsd.port.mk>
