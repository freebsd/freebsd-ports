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
.if !defined(WITHOUT_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
LIB_DEPENDS+=	iconv.3:${PORTSDIR}/converters/libiconv
.endif

USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ggi=${LOCALBASE}
.if !defined(WITHOUT_FREETYPE)
CONFIGURE_ARGS+=--with-ft-prefix=${LOCALBASE}
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

pre-everything::
.if !defined(WITHOUT_FREETYPE)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "ggiterm can be built without Freetype support. However, as the author says,"
	@${ECHO_MSG} "'if you don't have freetype you lose much of the ggiterm reason for being,'"
	@${ECHO_MSG} "so you probably don't want this. If you do, cancel now and build with:"
	@${ECHO_MSG} "  WITHOUT_FREETYPE=yes"
	@${ECHO_MSG} ""
.else
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You have chosen to build ggiterm without Freetype. If this wasn't your"
	@${ECHO_MSG} "intention, cancel now and unset the 'WITHOUT_FREETYPE' variable."
	@${ECHO_MSG} ""
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
