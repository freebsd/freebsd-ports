# New ports collection makefile for:	ratpoison
# Date created:		January 20, 2001
# Whom:			Gergely Nagy <8@free.bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	ratpoison
PORTVERSION=	0.0.5
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	8@free.bsd.hu

.if		defined(WITH_RXVT)
RUN_DEPENDS=	${X11BASE}/bin/rxvt:${PORTSDIR}/x11/rxvt
.endif

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.if		defined(WITH_RXVT)
pre-build:
		${PERL} -pi -e 's/xterm/rxvt/' ${WRKSRC}/src/actions.c
.endif

.if		defined(NOPORTDOCS)
INSTALL_TARGET=	SUBDIRS=src install
.endif

.include <bsd.port.mk>
