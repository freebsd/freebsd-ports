# New ports collection makefile for:    gdesklets-tasklist
# Date created:                		04 January 2004
# Whom:                    		Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$
#

PORTNAME=	tasklist
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	${PORTNAME}-desklet-${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Displays the GNOME tasklist and floats above the other windows

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

USE_BZIP2=	yes
USE_X_PREFIX=	yes

NAME=		tasklist
DATADIR=	${PREFIX}/share/gnome
PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}-desklet-${PORTVERSION}

do-build:
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; s|%%NAME%%|${NAME}|g' > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/*.png ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/gdesklets/Displays/${NAME}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
