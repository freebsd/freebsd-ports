# New ports collection makefile for:	wmappl
# Date created:				3 March 2002
# Whom:					od <od@iclub.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmappl
PORTVERSION=	0.71
CATEGORIES=	x11 windowmaker
MASTER_SITES=	SF/wmappl/wmappl/wmappl-${PORTVERSION}:main \
		http://www.upl.cs.wisc.edu/~charkins/wmappl/:icons
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main \
		16x16xpms.tar.gz:icons icons_16x16.tar.gz:icons smallicons.tar.gz:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An application launcher dockapp similar to wmbutton

GNU_CONFIGURE=	yes
USE_XORG=	xpm x11 xext sm ice
MAKE_ENV=	DATADIR="${DATADIR}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

MAN1=	wmappl.1
MAN5=	wmapplrc.5

post-extract:
	@${RM} -rf ${WRKSRC}/icons/CVS

post-install:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "===>   Installing icons to ${DATADIR} directory"
	@${MKDIR} ${DATADIR}
	@cd ${WRKDIR} && ${INSTALL_DATA} *.xpm ${DATADIR}
	@cd ${WRKDIR}/smallicons && ${INSTALL_DATA} *.xpm ${DATADIR}
.ifndef(NOPORTDOCS)
	@${ECHO_CMD} "===>   Installing README as ${DOCSDIR}/README"
	@${ECHO_CMD} "===>   Please read for configuration information"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
