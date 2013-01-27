# Created by: trevor
# $FreeBSD$

PORTNAME=	qlwm
PORTVERSION=	4.3
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.alinden.mynetcologne.de/qlwm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt-based window manager

USE_QT4=	corelib gui moc_build qmake_build

MAN1=		qlwm.1
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
		lib/qlwm/qlwm
PLIST_DIRS=	lib/qlwm/files \
		lib/qlwm

SUB_FILES=	qlwm

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/qlwm|${PREFIX}/lib/qlwm|g ; \
		 s|/usr/local/man|${MANPREFIX}/man|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/qlwm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qlwm.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/lib/qlwm
	${INSTALL_PROGRAM} ${WRKSRC}/dclock/dclock ${PREFIX}/lib/qlwm
	${INSTALL_PROGRAM} ${WRKSRC}/mail/biff ${PREFIX}/lib/qlwm
	${INSTALL_PROGRAM} ${WRKSRC}/src/qlwm ${PREFIX}/lib/qlwm
	@${MKDIR} ${PREFIX}/lib/qlwm/files
	${INSTALL_DATA} ${WRKSRC}/files/*.xpm ${PREFIX}/lib/qlwm/files
	${INSTALL_DATA} ${WRKSRC}/files/appdefaults ${PREFIX}/lib/qlwm/files
	${INSTALL_DATA} ${WRKSRC}/files/defaults ${PREFIX}/lib/qlwm/files
	${INSTALL_DATA} ${WRKSRC}/files/menuconfig ${PREFIX}/lib/qlwm/files
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
