# New ports collection makefile for:   render
# Date Created:			2 Jul, 2003
# Whom:				Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	renderext
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://pdx.freedesktop.org/~xlibs/release/
DISTNAME=	render-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Header files and documentation for the X render extension

PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes

.include <bsd.port.mk>
