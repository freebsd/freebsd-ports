# New ports collection makefile for:	ude
# Date created:		06 Mar 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	ude
PORTVERSION=	0.2.7b.1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ude.the-coffeeshop.dk/pub/UDE/
MASTER_SITE_SUBDIR=	udeproject
DISTNAME=	${PORTNAME}-0.2.7b-BETA

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ude
	${INSTALL_DATA} ${WRKSRC}/doc/*.lyx ${PREFIX}/share/doc/ude
	${INSTALL_DATA} ${WRKSRC}/doc/*.tex ${PREFIX}/share/doc/ude
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${PREFIX}/share/doc/ude
	@${MKDIR} ${PREFIX}/share/doc/ude/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${PREFIX}/share/doc/ude/html
	@${MKDIR} ${PREFIX}/share/doc/ude/html/uwm
	${INSTALL_DATA} ${WRKSRC}/doc/html/uwm/*.html ${PREFIX}/share/doc/ude/html/uwm
.endif

.include <bsd.port.mk>
