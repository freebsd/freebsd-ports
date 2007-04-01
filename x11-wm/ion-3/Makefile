# New ports collection makefile for:	ion3-ds
# Date created:				18 June 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	ion-3ds
PORTVERSION=	20070318
CATEGORIES=	x11-wm
MASTER_SITES=	http://modeemi.fi/~tuomov/dl/

MAINTAINER=	ed@fxq.nl
COMMENT=	The development version of the Ion window manager

RUN_DEPENDS=	run-mailcap:${PORTSDIR}/misc/mime-support

USE_X_PREFIX=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LUA=	5.1
MAKE_ENV=	DEFINES="${IONDEFINES}"

.if defined(WITHOUT_NLS)
IONDEFINES+=	-DCF_NO_LOCALE
.endif

MAN1=		ion3.1 pwm3.1
MANLANG=	"" fi cs de
DOCSDIR=	share/doc/ion3

# NO, I don't want to use configure but ion's author system.mk
do-configure:

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		needs wide character string functions in libc
.endif

.include <bsd.port.post.mk>
