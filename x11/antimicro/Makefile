# Created by: Anton Törnqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	antimicro
PORTVERSION=	2.13
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for mapping keyboard and mouse to a gamepad

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	Ryochan7

# Upstream assumes ${LOCALBASE}/lib is part of the default linker path. Pull
# request 268 fixes it for X11 libraries, but SDL2 is still using pkg-config
# output (without full paths).
LDFLAGS+=	-L${LOCALBASE}/lib

USE_XORG=	x11 xtst
USE_QT5=	linguisttools_build qmake_build buildtools_build widgets network
USE_SDL=	sdl2
USES=		cmake pkgconfig desktop-file-utils shared-mime-info

.include <bsd.port.mk>
