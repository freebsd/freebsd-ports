# Created by: od <od@iclub.nsu.ru>
# $FreeBSD$

PORTNAME=	wmappl
PORTVERSION=	0.71
CATEGORIES=	x11 windowmaker
MASTER_SITES=	SF/wmappl/wmappl/wmappl-${PORTVERSION}:main \
		http://www.upl.cs.wisc.edu/~charkins/wmappl/:icons
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main \
		16x16xpms.tar.gz:icons icons_16x16.tar.gz:icons smallicons.tar.gz:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application launcher dockapp similar to wmbutton

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-10

GNU_CONFIGURE=	yes
USE_XORG=	xpm x11 xext sm ice
MAKE_ENV=	DATADIR="${DATADIR}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
	@${RM} -rf ${WRKSRC}/icons/CVS

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKDIR} && ${INSTALL_DATA} *.xpm ${STAGEDIR}${DATADIR}
	@cd ${WRKDIR}/smallicons && ${INSTALL_DATA} *.xpm ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_CMD} "===>   Please read ${DOCSDIR}/README for configuration information"
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
