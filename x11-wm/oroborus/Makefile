# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oroborus
PORTVERSION=	2.0.18
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.oroborus.org/debian/dists/sid/main/source/x11/ \
		http://matt.peterson.org/FreeBSD/ports/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	matt@peterson.org
COMMENT=	Small and simple GNOME-compatible window manager

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XORG=	xpm
USES=		gmake
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
