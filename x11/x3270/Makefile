# New ports collection makefile for:	x3270
# Date created:		31 January 1995
# Whom:			janek
#
# $FreeBSD$
#

PORTNAME=	x3270
PORTVERSION=	3.3.2p1
CATEGORIES=	x11 net
MASTER_SITES=	http://x3270.bgp.nu/download/
DISTNAME=	${PORTNAME}-332p1
EXTRACT_SUFX=	.tgz

MAINTAINER=	Yonatan@xpert.com
COMMENT=	3270 Terminal emulator

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_IMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-pr3287 --with-fontdir=local --disable-dbcs
.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--disable-ssl
.else
USE_OPENSSL=	yes
.endif

WRKSRC=		${WRKDIR}/x3270-3.3
MAN1=		x3270.1
MANCOMPRESSED=	yes

pre-install:
.if !exists(${X11BASE}/lib/X11/fonts/local)
	@${ECHO} "*********************************************************"
	@${ECHO} "Please update your XFree86 to version 3.3.3 or later"
	@${ECHO} "or add ${X11BASE}/lib/X11/fonts/local to your font path"
	@${ECHO} "in /etc/XF86Config."
	@${ECHO} "*********************************************************"
.endif

.include <bsd.port.mk>
