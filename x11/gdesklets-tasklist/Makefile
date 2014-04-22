# Created by: Vincent Tantardini <vinc@FreeBSD-fr.org>
# $FreeBSD$

PORTNAME=	tasklist
PORTVERSION=	0.10
PORTREVISION=	12
CATEGORIES=	x11 gnome
MASTER_SITES=	http://gdesklets.zencomputer.ca/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	${PORTNAME}-desklet-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays the GNOME tasklist and floats above the other windows

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets

NAME=		tasklist
DATADIR=	${PREFIX}/share
PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}-desklet-${PORTVERSION}

do-build:
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; s|%%NAME%%|${NAME}|g' > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/gdesklets/Displays/${NAME}
	@${INSTALL_DATA} ${WRKSRC}/*.display ${STAGEDIR}${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/*.png ${STAGEDIR}${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DATADIR}/gdesklets/Displays/${NAME}/

.include <bsd.port.mk>
