PORTREVISION=	0
PKGNAMESUFFIX=	-opengl

COMMENT=	OpenGL renderer for MyGUI

MASTERDIR=	${.CURDIR}/../mygui

MYGUI_RENDERSYSTEM=	4
MYGUI_SUBDIR=		Platforms/OpenGL/OpenGLPlatform

USES=		gl localbase sdl
USE_GL=		gl glu opengl
USE_SDL=	image2

.include "${MASTERDIR}/Makefile"
