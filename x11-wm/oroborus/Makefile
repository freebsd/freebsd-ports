# New ports collection makefile for:	oroborus
# Date created:				19 April 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	oroborus
PORTVERSION=	2.0.12
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.oroborus.org/debian/dists/sid/main/source/x11/ \
		http://matt.peterson.org/FreeBSD/ports/
DISTNAME=	${PORTNAME}_${PORTVERSION}-1

MAINTAINER=	matt@peterson.org
COMMENT=	A small and simple GNOME-compatible window manager

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XPM=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		oroborus.1
MAN5=		oroborusrc.5

.include <bsd.port.mk>
