# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-edit
PORTVERSION=	08.08.06
CATEGORIES=	x11
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI to edit xorg.conf

LICENSE=	GPLv3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
DOS2UNIX_GLOB=	*.cpp *.h
USE_WX=		2.6+
WX_UNICODE=	yes
USES=		dos2unix gmake

PLIST_FILES=	bin/xorg-edit \
		lib/xorg-edit/de_DE/LC_MESSAGES/xorg-edit.mo \
		lib/xorg-edit/options/devices/example.xml \
		lib/xorg-edit/options/devices/list.xml \
		lib/xorg-edit/options/devices/nvidia.xml \
		lib/xorg-edit/xorg-edit
PLIST_DIRS=	lib/xorg-edit/options/devices \
		lib/xorg-edit/options \
		lib/xorg-edit/de_DE/LC_MESSAGES \
		lib/xorg-edit/de_DE \
		lib/xorg-edit

DESKTOP_ENTRIES="Xorg Edit" "" "" "${PORTNAME}" "Settings;" true

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|^CXX =|CXX ?=| ; \
		 s|^CXXFLAGS =|CXXFLAGS ?=|' ${WRKSRC}/libxorgedit/Makefile
	@${REINPLACE_CMD} -e \
		's|^CXXFLAGS =|CXXFLAGS +=| ; \
		 s|wx-config|$$(WX_CONFIG)| ; \
		 s|-O3|| ; \
		 s|^CXX =|CXX ?=| ; \
		 s|^LDFLAGS =|LDFLAGS +=| ; \
		 s|^$$(OBJECTS).*|%.o: %.c|' ${WRKSRC}/xorgedit/Makefile

do-configure:
	@${ECHO_CMD} -n > ${WRKDIR}/xorg-edit
	@${ECHO_CMD} '#!/bin/sh' >> ${WRKDIR}/xorg-edit
	@${ECHO_CMD} 'cd ${PREFIX}/lib/xorg-edit && ./xorg-edit "$$@"' \
		>> ${WRKDIR}/xorg-edit
	@${ECHO_CMD} -n > ${WRKSRC}/Makefile
	@${ECHO_CMD} 'all:' >> ${WRKSRC}/Makefile
	@${ECHO_CMD} '	$$(MAKE) -C libxorgedit' >> ${WRKSRC}/Makefile
	@${ECHO_CMD} '	$$(MAKE) -C xorgedit' >> ${WRKSRC}/Makefile

do-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} xorg-edit ${PREFIX}/bin)
	@${MKDIR} ${PREFIX}/lib/xorg-edit
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} xorg-edit \
		${PREFIX}/lib/xorg-edit)
	@${MKDIR} ${PREFIX}/lib/xorg-edit/de_DE/LC_MESSAGES
	(cd ${WRKSRC}/de_DE/LC_MESSAGES && ${INSTALL_DATA} ${PORTNAME}.mo \
		${PREFIX}/lib/xorg-edit/de_DE/LC_MESSAGES)
	@${MKDIR} ${PREFIX}/lib/xorg-edit/options/devices
	(cd ${WRKSRC}/options/devices && ${INSTALL_DATA} *.xml \
		${PREFIX}/lib/xorg-edit/options/devices)

.include <bsd.port.mk>
