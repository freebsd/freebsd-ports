# New ports collection makefile for:	vtwm
# Date created:		21 December 1998
# Whom:			bmah@ca.sandia.gov
#
# $FreeBSD$
#

PORTNAME=	vtwm
PORTVERSION=	5.4.7
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.vtwm.org/downloads/

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	Twm with a virtual desktop and optional Motif-like features

USE_IMAKE=	yes
USE_XPM=	yes

MAN1=		vtwm.1

OPTIONS=	SOUND "Sound support" on

.include <bsd.port.pre.mk>

post-patch:
.if defined(WITHOUT_SOUND)
	@${REINPLACE_CMD} -i "" -e \
		's:^XCOMM NO_SOUND_SUPPORT: NO_SOUND_SUPPORT:; \
		s:^SOUNDLIB:XCOMM SOUNDLIB:; \
		s:^SOUNDINC:XCOMM SOUNDINC: ' ${WRKSRC}/Imakefile
.else
LIB_DEPENDS+=	rplay.1:${PORTSDIR}/audio/rplay
.endif

.include <bsd.port.post.mk>
