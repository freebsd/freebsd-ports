# New ports collection makefile for:   render
# Date Created:			2 Jul, 2003
# Whom:				Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	render
PORTVERSION=	0.8
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://fontconfig.org/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Header files and documentation for the X render extension

USE_X_PREFIX=	yes
CONFIGURE_ARGS=	--prefix=${X11BASE}

pre-build:
	@(cd ${WRKSRC}; ./configure ${CONFIGURE_ARGS})

.include <bsd.port.mk>
