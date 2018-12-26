# Created by: Anton Toernqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	antimicro
PORTVERSION=	2.23
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for mapping keyboard and mouse to a gamepad

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	antimicro #Ryochan7

# Upstream assumes ${LOCALBASE}/lib is part of the default linker path. Pull
# request 268 fixes it for X11 libraries, but SDL2 is still using pkg-config
# output (without full paths).
LDFLAGS+=	-L${LOCALBASE}/lib

USES=		cmake compiler:c++11-lang desktop-file-utils pkgconfig \
		qt:5 shared-mime-info
USE_XORG=	x11 xi xtst
USE_QT=		core gui linguisttools_build qmake_build buildtools_build widgets network
USE_SDL=	sdl2

.include <bsd.port.mk>
