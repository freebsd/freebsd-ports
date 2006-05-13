# New ports collection makefile for:	tpager
# Date created:				Feb 12 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	tpager
PORTVERSION=	0.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://s1x.homelinux.net/files/

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Lightweight EMWH Compliant Pager

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_BZIP2=	yes

PLIST_FILES=	bin/tpager

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/X11R6#${X11BASE}#' ${WRKSRC}/Makefile

.include <bsd.port.mk>
