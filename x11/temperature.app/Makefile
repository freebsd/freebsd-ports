# New ports collection makefile for:	Temperature.app
# Date created:				06 May 2001
# Whom:					Per Otterstr=F6m <pelle@fukt.bth.se>
#
# $FreeBSD$
#

PORTNAME=	temperature.app
PORTVERSION=	1.3
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://www.fukt.bth.se/~per/temperature/
DISTNAME=	Temperature.app-${PORTVERSION}

MAINTAINER=	pelle@fukt.bth.se

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

USE_XPM=	yes
USE_X_PREFIX=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/Temperature.app ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} \
		${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
