# New ports collection makefile for:	ggiterm
# Date created:		20 October 2003
# Whom:			andi_payn@speedymail.com
#
# $FreeBSD$
#

PORTNAME=	ggiterm
PORTVERSION=	0.7.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggiterm
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	antoine.brodin@laposte.net
COMMENT=	A terminal emulator for GGI

LIB_DEPENDS=	ggi.2:${PORTSDIR}/graphics/libggi

USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ggi-prefix=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS=	FREETYPE "Build with Freetype support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
USE_ICONV=	yes
CONFIGURE_ARGS+=--with-ft-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-freetype
.endif

MAN1=		ggiterm.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
