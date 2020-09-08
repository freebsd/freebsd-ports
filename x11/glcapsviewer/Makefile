# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glcapsviewer
DISTVERSION=	g20190521
CATEGORIES=	x11

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	OpenGL hardware capability viewer

LICENSE=	LGPL3

LIB_DEPENDS=	libglfw.so:graphics/glfw

USE_GITHUB=	yes
GH_ACCOUNT=	SaschaWillems
GH_PROJECT=	glCapsViewer
GH_TAGNAME=	26e160c

USES=		cmake compiler:c++11-lang gl qt:5 xorg
USE_GL=		gl glew glu
USE_QT=		buildtools_build qmake_build core gui network widgets
USE_XORG=	ice sm x11 xext

PLIST_FILES=	bin/glcapsviewer ${DATADIR_REL}/capslist.xml \
		${DATADIR_REL}/enumList.xml

post-patch:
	@${REINPLACE_CMD} -e '/target_link_libraries/s,glfw ,,' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,__linux__,__${OPSYS}__, ; /ifstream\
		enumListxml/s,[^"]*ist\.xml",${DATADIR}/&,' \
		${WRKSRC}/glCapsViewer.cpp ${WRKSRC}/glCapsViewerCore.cpp
# We install provided `capslist.xml' in the ${DATADIR}, hence disable
# checking for ./capslist.xml and needlessly downloading it
	@${REINPLACE_CMD} -e 's,!capsXmlFile\.exists,false \&\& &,' \
		${WRKSRC}/main.cpp
# Spell XML correctly (it is an abbreviation)
	@${REINPLACE_CMD} -e 's, xml, XML,' ${WRKSRC}/glCapsViewer.ui
# Copyright information does not belong in the window title
	@${REINPLACE_CMD} -e 's, - [^"]*,,' ${WRKSRC}/glCapsViewerCore.h

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.xml ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
