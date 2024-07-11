PORTNAME=	boomer
PORTVERSION=	0.0.1
CATEGORIES=	x11

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Screen zoom and highlight program for X11
WWW=		https://github.com/tsoding/boomer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nimble:devel/nimble
RUN_DEPENDS=	${LOCALBASE}/lib/libGL.so:graphics/libglvnd \
		${LOCALBASE}/lib/libX11.so:x11/libX11 \
		${LOCALBASE}/lib/libXrandr.so:x11/libXrandr

USE_GITHUB=	yes
GH_ACCOUNT=	tsoding nim-lang:x11,opengl
GH_PROJECT=	x11:x11 opengl:opengl
GH_TAGNAME=	dfd4e1f 1.2:x11 1.2.9:opengl
GH_SUBDIR=	nimbledeps/pkgs2/x11-1.2:x11 \
		nimbledeps/pkgs2/opengl-1.2.9:opengl

PLIST_FILES=	bin/${PORTNAME}

post-patch:
.for pkg in x11 opengl
	${LN} -s ${FILESDIR}/${pkg}-nimblemeta.json \
		${WRKSRC_${pkg}}/nimblemeta.json
.endfor
	${MV} ${WRKSRC_opengl}/src/opengl* ${WRKSRC_opengl}

do-build:
	cd ${BUILD_WRKSRC} && nimble build --nim=${LOCALBASE}/nim/bin/nim \
	--localdeps --offline --reject --verbose -d:release -d:nimDebugDlOpen

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
