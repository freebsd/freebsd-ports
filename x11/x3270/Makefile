# New ports collection makefile for:	x3270
# Date created:		31 January 1995
# Whom:			janek
#
# $FreeBSD$
#

PORTNAME=	x3270
PORTVERSION=	3.1.1.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	Yonatan@xpert.com
COMMENT=	3270 Terminal emulator

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_IMAKE=	yes

WRKSRC=		${WRKDIR}/x3270-3.1.1
MAN1=		x3270.1 x3270if.1 x3270-script.1 ibm_hosts.1
MANCOMPRESSED=	yes
USE_REINPLACE=	yes

pre-install:
.if !exists(${X11BASE}/lib/X11/fonts/local)
	@${ECHO} "*********************************************************"
	@${ECHO} "Please update your XFree86 to version 3.3.3 or later"
	@${ECHO} "or add ${X11BASE}/lib/X11/fonts/local to your font path"
	@${ECHO} "in /etc/XF86Config."
	@${ECHO} "*********************************************************"
.endif

#
# This patch is to make sure that mkversion.sh can be ran on FreeBSD 4-STABLE
# which will get $(CLIENTENVSETUP) in its CC macro.
#
post-configure:
	${REINPLACE_CMD} \
	    -e 's,sh \./mkversion\.sh $$(CC),$$(CLIENTENVSETUP) sh ./mkversion.sh %%CC%%,' \
	    -e 's,%%CC%%,${CC},' \
	    ${WRKSRC}/Makefile

.include <bsd.port.mk>
