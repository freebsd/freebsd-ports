PORTREVISION=	0
PKGNAMESUFFIX=	-opengles

COMMENT=	OpenGLES renderer for MyGUI

MASTERDIR=	${.CURDIR}/../mygui

MYGUI_RENDERSYSTEM=	8
MYGUI_SUBDIR=		Platforms/OpenGLES/OpenGLESPlatform

USES=		gl localbase sdl
USE_GL=		gl glesv1 glesv2 glu opengl
USE_SDL=	image2

.include "${MASTERDIR}/Makefile"
