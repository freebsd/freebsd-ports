# New ports collection makefile for:	ggiterm
# Date created:		20 October 2003
# Whom:			andi_payn@speedymail.com
#
# $FreeBSD$
#

PORTNAME=	ggiterm
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggiterm
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A terminal emulator for GGI

LIB_DEPENDS=	ggi.2:${PORTSDIR}/graphics/libggi

USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ggi=${LOCALBASE}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS=	FREETYPE "Build with Freetype support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
USE_ICONV=	yes
CONFIGURE_ARGS+=--with-ft-prefix=${LOCALBASE}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
