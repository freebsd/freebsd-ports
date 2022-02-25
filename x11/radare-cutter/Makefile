PORTNAME=	radare-cutter
PORTVERSION=	0.1.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	swills@FreeBSD.org
COMMENT=	GUI for radare2 reverse engineering framework

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libcapstone.so:devel/capstone4 \
		libr_bin.so:devel/radare2

USES=		cmake gl pkgconfig python:3.4+ qmake:outsource qt:5
LDFLAGS+=	-lexecinfo

USE_GITHUB=	yes
GH_ACCOUNT=	radareorg
GH_PROJECT=	r2cutter
GH_TUPLE=	radareorg:cutter-translations:8e1d24b:translations/translations

USE_QT=		core declarative gui linguist location network printsupport svg \
		webchannel widgets buildtools_build
USE_GL=		gl

WRKSRC_SUBDIR=	src

CMAKE_INSTALL_PREFIX=	${STAGEDIR}${PREFIX}

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386
USE_QT+=	webengine
.endif

post-patch:
	@${REINPLACE_CMD} 's/python3/python-${PYTHON_VER}/' ${WRKSRC}/Cutter.pro

.include <bsd.port.mk>
