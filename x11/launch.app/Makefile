# New ports collection makefile for:	launch.app
# Date created:				20 August 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	launch.app
PORTVERSION=	0.7.0
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://stepmaker.sourceforge.net/launch/
DISTNAME=	${PORTNAME:S/l/L/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

FORBIDDEN=	"Buffer overflows in setuid root code"

LIB_DEPENDS=	wraster.4:${PORTSDIR}/x11-wm/windowmaker

WRKSRC=		${WRKDIR}/${PORTNAME:S/l/L/}

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ENV=	MKDIR="${MKDIR}"

.include <bsd.port.mk>
