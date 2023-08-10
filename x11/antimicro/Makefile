PORTNAME=	antimicro
PORTVERSION=	2.23
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for mapping keyboard and mouse to a gamepad
WWW=		https://github.com/AntiMicro/antimicro

LICENSE=	GPLv3

DEPRECATED=	Replaced by x11/antimicrox upstream no longer maintained
EXPIRATION_DATE=	2023-10-01

USES=		cmake compiler:c++11-lang desktop-file-utils pkgconfig \
		qt:5 sdl shared-mime-info xorg
USE_GITHUB=	yes
GH_ACCOUNT=	antimicro #Ryochan7
USE_QT=		core gui linguisttools:build qmake:build buildtools:build widgets network
USE_SDL=	sdl2
USE_XORG=	x11 xi xtst

# Upstream assumes ${LOCALBASE}/lib is part of the default linker path. Pull
# request 268 fixes it for X11 libraries, but SDL2 is still using pkg-config
# output (without full paths).
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
