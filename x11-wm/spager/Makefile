# New ports collection makefile for:   sawfish pager
# Date created:        05 June 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spager
PORTVERSION=	0.15
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.stanford.edu/~satyakid/

MAINTAINER=	nakai@FreeBSD.org

RUN_DEPENDS=	sawfish:${PORTSDIR}/x11-wm/sawfish

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12

ALL_TARGET=	spager

post-extract:
	${RM} -f ${WRKSRC}/spager

post-patch:
	${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/sample.rc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spager ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/spager.jl ${DATADIR}
	${MKDIR} ${DATADIR}/merlin
	${INSTALL_SCRIPT} ${WRKSRC}/merlin/message.jl ${DATADIR}/merlin
	${INSTALL_SCRIPT} ${WRKSRC}/merlin/util.jl ${DATADIR}/merlin
	${INSTALL_DATA} ${WRKSRC}/sample.rc ${DATADIR}
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
