# ex:ts=8
# Ports collection makefile for:	xvattr
# Date created:			Jan 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xvattr
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Getting and setting Xv attributes

USE_X_PREFIX=	yes
USE_PERL5_BUILD=	yes
USE_GETOPT_LONG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		xvattr.1

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xfree86-3
IGNORE=		"Requires Xv Extension"
.endif

.include <bsd.port.post.mk>
