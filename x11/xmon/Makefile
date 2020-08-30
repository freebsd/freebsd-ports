# Created by: Bruce M Simpson <bms@spc.org>
# $FreeBSD$

PORTNAME=	xmon
PORTVERSION=	1.5.6
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	XCONTRIB/devel_tools
DISTNAME=	xmon.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Raw X11 protocol analyser

# Fix build with -fno-common (llvm 11)
CFLAGS+=	-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

WRKSRC=		${WRKDIR}/xmon.${PORTVERSION}
USES=		imake xorg
USE_XORG=	ice sm x11 xaw xext xmu xt

.include <bsd.port.mk>
