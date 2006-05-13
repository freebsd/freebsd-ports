# New ports collection makefile for: imwheel-0.9.7
# Date created:		18 Feb 2000
# Whom:			jhb
#
# $FreeBSD$
#

PORTNAME=	imwheel
PORTVERSION=	1.0.0.p12
CATEGORIES=	x11
MASTER_SITES=	ftp://jcatki.no-ip.org/pub/imwheel/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p12/pre12/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to translate mouse wheel actions into X keyboard events

USE_GMAKE=	YES
USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-gpm

MAN1=		imwheel.1

post-patch:
.for i in imwheel.1 util.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${i}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/EMACS ${DOCSDIR}
.endif

.include <bsd.port.mk>
