# New ports collection makefile for: imwheel-0.9.7
# Date created:		18 Feb 2000
# Whom:			jhb
#
# $FreeBSD$
#

PORTNAME=	imwheel
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://jonatkins.org/imwheel/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to translate mouse wheel actions into X keyboard events

USE_REINPLACE=	yes
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
	${MKDIR} ${PREFIX}/share/doc/imwheel
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/EMACS \
		 ${PREFIX}/share/doc/imwheel
.endif

.include <bsd.port.mk>
