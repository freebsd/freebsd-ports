# Created by: trevor
# $FreeBSD$

PORTNAME=	qlwm
PORTVERSION=	4.3
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.alinden.mynetcologne.de/qlwm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt-based window manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_JOBS_UNSAFE= yes

USE_QT4=	corelib gui moc_build qmake_build

PORTDOCS=	CHANGES README

SUB_FILES=	qlwm

OPTIONS_DEFINE=	DOCS

post-patch:
	@${ECHO} "QMAKE_LFLAGS= -lXext -lX11" >> /${WRKSRC}/src/qlwm.pro
	@${REINPLACE_CMD} -e 's|/usr/local/qlwm|${PREFIX}/lib/qlwm|g ; \
		 s|/usr/local/man|${MANPREFIX}/man|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/qlwm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qlwm.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/qlwm
	${INSTALL_PROGRAM} ${WRKSRC}/dclock/dclock ${STAGEDIR}${PREFIX}/lib/qlwm
	${INSTALL_PROGRAM} ${WRKSRC}/mail/biff ${STAGEDIR}${PREFIX}/lib/qlwm
	${INSTALL_PROGRAM} ${WRKSRC}/src/qlwm ${STAGEDIR}${PREFIX}/lib/qlwm
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/qlwm/files
	${INSTALL_DATA} ${WRKSRC}/files/*.xpm ${STAGEDIR}${PREFIX}/lib/qlwm/files
	${INSTALL_DATA} ${WRKSRC}/files/appdefaults ${STAGEDIR}${PREFIX}/lib/qlwm/files
	${INSTALL_DATA} ${WRKSRC}/files/defaults ${STAGEDIR}${PREFIX}/lib/qlwm/files
	${INSTALL_DATA} ${WRKSRC}/files/menuconfig ${STAGEDIR}${PREFIX}/lib/qlwm/files

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
