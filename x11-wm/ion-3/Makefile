# New ports collection makefile for:	ion3-ds
# Date created:				18 June 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	ion-3ds
PORTVERSION=	20050728
CATEGORIES=	x11-wm
MASTER_SITES=	http://modeemi.fi/~tuomov/ion/dl/

MAINTAINER=	ed@fxq.nl
COMMENT=	The development version of the Ion window manager

LIB_DEPENDS=	lua.5:${PORTSDIR}/lang/lua
RUN_DEPENDS=	run-mailcap:${PORTSDIR}/misc/mime-support

CONFLICTS=	ion-2002* pwm-* ion-2*

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ENV=	DEFINES="${IONDEFINES}"

.if !defined(WITH_XINERAMA)
IONDEFINES+=	-DCF_NO_XINERAMA
.endif

.if defined(WITHOUT_NLS)
IONDEFINES+=	-DCF_NO_LOCALE
.endif

MAN1=		ion3.1 pwm3.1
DOCSDIR=	share/doc/ion3

# NO, I don't want to use configure but ion's author system.mk
do-configure:

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		needs wide character string functions in libc
.endif

.include <bsd.port.post.mk>
