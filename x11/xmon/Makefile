# New ports collection makefile for:    xmon
# Date created:         27 December 2001
# Whom:                 Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$
#

PORTNAME=	xmon
PORTVERSION=	1.5.6
CATEGORIES=	x11
MASTER_SITES=	http://www.ibiblio.org/pub/X11/contrib/devel_tools/ \
		ftp://ftp.x.org/contrib/devel_tools/
DISTNAME=	xmon.${PORTVERSION}

MAINTAINER=	bms@spc.org
COMMENT=	Raw X11 protocol analyser

WRKSRC=		${WRKDIR}/xmon.${PORTVERSION}
USE_IMAKE=	yes

MAN1=		xmon.1 xmond.1 xmonui.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
