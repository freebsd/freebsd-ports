# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lxmed
PORTVERSION=	20120515
PORTREVISION=	2
CATEGORIES=	x11-wm java
MASTER_SITES=	SF/${PORTNAME}/
DIST_SUBDIR=	java

MAINTAINER=	horia@racoviceanu.com
COMMENT=	LXDE Main Menu Editor

LICENSE=	GPLv3

RUN_DEPENDS=	gksu:sysutils/gksu

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}.sh ${PORTNAME}-root

post-extract:
	@(cd ${WRKSRC}/content/ && ${CP} -a ${PORTNAME}.desktop \
		${PORTNAME}-root.desktop)

post-patch:
	@${REINPLACE_CMD} -e 's|/opt/lxmed/${PORTNAME}.png|${PORTNAME}|; \
		s|Main Menu Editor|${COMMENT}|' \
		${WRKSRC}/content/${PORTNAME}.desktop
	@${REINPLACE_CMD} -e 's|/opt/lxmed/${PORTNAME}.png|${PORTNAME}|; \
		s|Exec=lxmed|Exec=${PORTNAME}-root ${PORTNAME}|; \
		s|Main Menu Editor|${COMMENT} (as root)|' \
		${WRKSRC}/content/${PORTNAME}-root.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-root \
		${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -a ${FILESDIR}/pc-su ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/content/LXMenuEditor.jar ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/content/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/content/*.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
