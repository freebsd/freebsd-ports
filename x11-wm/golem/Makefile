# New ports collection makefile for:   golem
# Date created:        11 August 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	golem
PORTVERSION=	0.0.5
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	fracture@allusion.net
COMMENT=	Small window manager with themes and plugins

.if defined(WANT_SOUND)
LIB_DEPENDS=	esd.2:${PORTSDIR}/audio/esound
CONFIGURE_ARGS=	--enable-sound
PLIST_SUB+=	NO_SOUND=""
.else
PLIST_SUB+=	NO_SOUND="@comment "
.endif

.if defined(WANT_XINERAMA)
CONFIGURE_ARGS+=	--enable-xinerama
.endif

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes

MANCOMPRESSED=	yes
MAN1=		golem.1

.include <bsd.port.mk>
