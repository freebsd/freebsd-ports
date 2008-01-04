# New ports collection makefile for:	vtwm
# Date created:		21 December 1998
# Whom:			bmah@ca.sandia.gov
#
# $FreeBSD$
#

PORTNAME=	vtwm
PORTVERSION=	5.4.7
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.vtwm.org/downloads/

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	Twm with a virtual desktop and optional Motif-like features

USE_XORG=	xpm xmu

ETCDIR?=	${PREFIX}/etc

MAKEFILE=	${FILESDIR}/Makefile.bsd

MAN1=		vtwm.1

OPTIONS=	SOUND "Sound support" on \
		NLS "Native language support" on

.include <bsd.port.pre.mk>

.if defined(WITH_SOUND)
LIB_DEPENDS+=	rplay.1:${PORTSDIR}/audio/rplay
MAKE_ENV+=	SOUND=yes
.else
MAKE_ENV+=	SOUND=no
.endif

.if defined(WITHOUT_NLS)
CFLAGS+=	-DNO_I18N_SUPPORT
.endif

.include <bsd.port.post.mk>
