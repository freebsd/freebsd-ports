# Created by: gahr
# $FreeBSD$

PORTNAME=	vtkfox
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.gahr.ch/vtkfox/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	FOX/VTK Widget and Interactor

LIB_DEPENDS=	vtkCommon.5:${PORTSDIR}/math/vtk5

OPTIONS_SINGLE=	FOX
OPTIONS_SINGLE_FOX=	FOX16 FOX17
FOX16_DESC=	Link against FOX-1.6
FOX17_DESC=	Link against FOX-1.7
OPTIONS_DEFAULT=FOX16

USE_GITHUB=	yes
GH_ACCOUNT=	gahr
GH_COMMIT=	378836c

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFOX16}
LIB_DEPENDS+=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16
.endif

.if ${PORT_OPTIONS:MFOX17}
LIB_DEPENDS+=	FOX-1.7:${PORTSDIR}/x11-toolkits/fox17
CMAKE_ARGS+=	-DFOX17:BOOL=TRUE
.endif

USES=		cmake:outsource
USE_LDCONFIG=	yes

PLIST_FILES=	include/vtkfox/FXVTKCanvas.h \
		include/vtkfox/vtkFXRenderWindowInteractor.h \
		include/vtkfox/vtkfox.h \
		lib/libvtkfox.so \
		lib/libvtkfox.so.1 \
		libdata/pkgconfig/vtkfox.pc
PLIST_DIRS=	include/vtkfox

post-patch:
.if defined(NOPORTEXAMPLES)
	${REINPLACE_CMD} -e 's| tests||' ${WRKSRC}/CMakeLists.txt
.endif

.if !defined(NOPORTEXAMPLES)
SAMPLE_FILES=	imgsurf double cone quad xyplot simple
PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${EXAMPLESDIR}
.for sample_file in ${SAMPLE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/tests/${sample_file}.cpp ${EXAMPLESDIR}
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/tests/${sample_file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
