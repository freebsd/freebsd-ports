# New ports collection makefile for:   sawfish pager
# Date created:        05 June 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spager
PORTVERSION=	0.08
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.stanford.edu/~satyakid/

MAINTAINER=	nakai@FreeBSD.org

RUN_DEPENDS=	sawfish:${PORTSDIR}/x11-wm/sawfish
LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

ALL_TARGET=	spager
USE_X_PREFIX=	yes

pre-build:
		${RM} -f ${WRKSRC}/spager

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/spager ${PREFIX}/bin/
		${MKDIR} ${PREFIX}/share/spager
		${INSTALL_SCRIPT} ${WRKSRC}/spager.jl ${PREFIX}/share/spager
		${INSTALL_SCRIPT} ${WRKSRC}/x-message.jl ${PREFIX}/share/spager
		${INSTALL_DATA} ${WRKSRC}/sample.rc ${PREFIX}/share/spager

post-install:
		@${ECHO_MSG} "*******************************************"
		@${ECHO_MSG} " Append ${PREFIX}/share/spager/sample.rc "
		@${ECHO_MSG} " to your ~/.sawfishrc"
		@${ECHO_MSG} "*******************************************"

.include <bsd.port.mk>
