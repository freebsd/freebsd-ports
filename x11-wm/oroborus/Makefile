# New ports collection makefile for:	oroborus
# Date created:				19 April 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	oroborus
PORTVERSION=	1.10
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.kensden.pwp.blueyonder.co.uk/Oroborus/
DISTNAME=	${PORTNAME}-src-v${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XPM=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes

do-install:
	${MKDIR} ${PREFIX}/share/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${WRKSRC}/install_rc ${PREFIX}/share/${PORTNAME}/pixmaps/default > \
		${WRKDIR}/${PORTNAME}rc
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}rc ${PREFIX}/share/${PORTNAME}
.for dir in agua default defold mac next win95
	${MKDIR} ${PREFIX}/share/${PORTNAME}/pixmaps/${dir}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/${dir}/[^.]* \
		${PREFIX}/share/${PORTNAME}/pixmaps/${dir}
.endfor

.include <bsd.port.mk>
