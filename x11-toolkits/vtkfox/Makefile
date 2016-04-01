# Created by: gahr
# $FreeBSD$

PORTNAME=	vtkfox
PORTVERSION=	1.0.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.gahr.ch/vtkfox/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FOX/VTK Widget and Interactor

LIB_DEPENDS=	libvtkCommon.so.5:math/vtk5

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SINGLE=	FOX
OPTIONS_SINGLE_FOX=	FOX16 FOX17
FOX16_DESC=	Link against FOX-1.6
FOX17_DESC=	Link against FOX-1.7
OPTIONS_DEFAULT=FOX16

USE_GITHUB=	yes
GH_ACCOUNT=	gahr

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFOX16}
LIB_DEPENDS+=	libFOX-1.6.so:x11-toolkits/fox16
CMAKE_ARGS+=	-DFOX17:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MFOX17}
LIB_DEPENDS+=	libFOX-1.7.so:x11-toolkits/fox17
CMAKE_ARGS+=	-DFOX17:BOOL=TRUE
.endif

USES=		cmake:outsource pkgconfig
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DVTK_DIR:PATH=${LOCALBASE}/lib/vtk-5.10

PLIST_FILES=	include/vtkfox/FXVTKCanvas.h \
		include/vtkfox/vtkFXRenderWindowInteractor.h \
		include/vtkfox/vtkfox.h \
		lib/libvtkfox.so \
		lib/libvtkfox.so.1 \
		libdata/pkgconfig/vtkfox.pc

SAMPLE_FILES=	imgsurf double cone quad xyplot simple
PORTEXAMPLES=	*

.if !${PORT_OPTIONS:MEXAMPLES}
post-patch:
	${REINPLACE_CMD} -e 's| tests||' ${WRKSRC}/CMakeLists.txt
.else
post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for sample_file in ${SAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/tests/${sample_file}.cpp ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/tests/${sample_file} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
