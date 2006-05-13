# New ports collection makefile for:   w9wm
# Date created:        25 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	w9wm
PORTVERSION=	0.4.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.grassouille.org/code/w9wm/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A hack of 9wm to give virtual screens

WRKSRC=		${WRKDIR}/${DISTNAME}.orig

USE_IMAKE=	yes

MAN1=		w9wm.1
PLIST_FILES=	bin/w9wm

post-patch:
	@${REINPLACE_CMD} -e '/malloc\.h/d' ${WRKSRC}/client.c

.include <bsd.port.mk>
