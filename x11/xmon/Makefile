# New ports collection makefile for:    xmon
# Date created:         27 December 2001
# Whom:                 Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$
#

PORTNAME=	xmon
PORTVERSION=	1.5.6
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	devel_tools
DISTNAME=	xmon.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Raw X11 protocol analyser

WRKSRC=		${WRKDIR}/xmon.${PORTVERSION}
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xt

MAN1=		xmon.1 xmond.1 xmonui.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
