# New ports collection makefile for:    mgapdesk
# Date created:		2001/06/02
# Whom:			Nick Sayer
#
# $FreeBSD$
#

PORTNAME=	mgapdesk
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.matrox.com/pub/mga/archive/linux/2001/powerdesk_1_00_7/
DISTNAME=	${PORTNAME}-1_00-7beta_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Matrox Powerdesk for *nix

USE_X_PREFIX=	YES
USE_GNOME=	gtk12

USE_GMAKE=	YES

USE_AUTOCONF=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if (${ARCH} == "alpha")
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -lio"
.endif

post-extract:
		@${RM} -f ${WRKSRC}/config.cache
		@${CHMOD} 750 ${WRKSRC}/missing

.include <bsd.port.post.mk>
