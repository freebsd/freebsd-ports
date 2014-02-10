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

MAKE_JOBS_UNSAFE= yes

USE_QT4=	corelib gui moc_build qmake_build

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CHANGES README
PLIST_FILES=	bin/qlwm \
		lib/qlwm/biff \
		lib/qlwm/dclock \
		lib/qlwm/files/appdefaults \
		lib/qlwm/files/button_left.xpm \
		lib/qlwm/files/button_right.xpm \
		lib/qlwm/files/defaults \
		lib/qlwm/files/menu.xpm \
		lib/qlwm/files/menuconfig \
		lib/qlwm/files/tiled.xpm \
		lib/qlwm/files/winlist.xpm \
		lib/qlwm/qlwm \
		man/man1/qlwm.1.gz
PLIST_DIRS=	lib/qlwm/files \
		lib/qlwm

SUB_FILES=	qlwm

post-patch:
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
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
