# New ports collection makefile for:	ggiterm
# Date created:		20 October 2003
# Whom:			andi_payn@speedymail.com
#
# $FreeBSD$
#

PORTNAME=	ggiterm
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A terminal emulator for GGI

LIB_DEPENDS=	ggi.2:${PORTSDIR}/graphics/libggi

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ggi-prefix=${LOCALBASE}
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	FREETYPE DOCS
OPTIONS_DEFAULT=	FREETYPE

PORTDOCS=	AUTHORS README

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
USE_ICONV=	yes
CONFIGURE_ARGS+=--with-ft-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-freetype
.endif

MAN1=		ggiterm.1

post-install:
	@${INSTALL_DATA} ${WRKSRC}/ggiterm.termcap ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
