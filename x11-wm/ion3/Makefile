# New ports collection makefile for:   ion-2
# Date created:        20 August 2003
# Whom:                anthony.ginepro@laposte.net
# Original ion port:   ricci@cs.utah.edu
#
# $FreeBSD$
#

PORTNAME=	ion3
PORTVERSION=	20080207
CATEGORIES=	x11-wm
MASTER_SITES=	http://modeemi.fi/~tuomov/dl/
DISTNAME=	${PORTNAME:C/([0-9])/-\1/}-${PORTVERSION}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	A tiling tabbed window manager

USE_XORG=	x11 xext
USE_LUA=	5.1
USE_GMAKE=	yes
USE_GETTEXT=yes
# ion3 clobbers $CFLAGS because it hates puppies
MAKE_ENV=	PORT_CFLAGS="${CFLAGS}"

MANLANG=	"" cs fi
MAN1=		ion3.1 pwm3.1

.include <bsd.port.mk>
