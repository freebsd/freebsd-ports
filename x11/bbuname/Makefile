# New ports collection makefile for:	bbuname
# Date created:				11 February 2004
# Whom:					Nikos "Noth" Ntarmos <ntarmos@ceid.upatras.gr>
#
# $FreeBSD$
#

PORTNAME=	bbuname
PORTVERSION=	0.2
CATEGORIES=	x11
MASTER_SITES=	http://spiritisdigital.com/download/linux/bbuname/

PATCH_SITES=	ftp://noth.ceid.upatras.gr/pub/FreeBSD/patches/
PATCHFILES=	${PORTNAME}-${PORTVERSION}.patch1.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Flux/Black-box applet displaying system information a la GNU uname

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

.include <bsd.port.mk>
