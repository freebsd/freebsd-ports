# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lxmed
PORTVERSION=	20120515
CATEGORIES=	x11-wm java
MASTER_SITES=	SF/${PORTNAME}/
DIST_SUBDIR=	java

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	LXDE Main Menu Editor

LICENSE=	GPLv3

RUN_DEPENDS=	gksu:${PORTSDIR}/sysutils/gksu

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}.sh

post-patch:
	@${REINPLACE_CMD} -e 's|/opt/lxmed/${PORTNAME}.png|${PREFIX}/share/pixmaps/${PORTNAME}.png|' \
		-e 's|Main Menu Editor|${COMMENT}|g' \
		${WRKSRC}/content/${PORTNAME}.desktop
	@(cd ${WRKSRC}/content/ && ${CP} -a ${PORTNAME}.desktop ${PORTNAME}-root.desktop)
	@${REINPLACE_CMD} -e 's|Exec=lxmed|Exec=${DATADIR}/pc-su ${PORTNAME}|' \
		-e 's|${COMMENT}|${COMMENT} (as root)|g' \
		${WRKSRC}/content/${PORTNAME}-root.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -a ${FILESDIR}/pc-su ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/content/LXMenuEditor.jar ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/content/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}

.for d in ${PORTNAME}.desktop ${PORTNAME}-root.desktop
	${INSTALL_DATA} ${WRKSRC}/content/${d} ${STAGEDIR}${DESKTOPDIR}
.endfor

.include <bsd.port.mk>
