# ex:ts=8
# Ports collection makefile for:	wmDrawer
# Date created:			Apr 6, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wmdrawer
PORTVERSION=	0.9.17.1
PORTREVISION=	1
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://people.easter-eggs.org/~valos/wmdrawer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockapp which provides a drawer to launch applications

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt" DOCSDIR=${DOCSDIR}

MANCOMPRESSED=	yes
MAN1=	wmdrawer.1x

.include <bsd.port.mk>
