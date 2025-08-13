PORTNAME=	contour
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1.7494
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Modern C++ terminal emulator
WWW=		https://contour-terminal.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/cmake/boxed-cpp/boxed-cpp-config.cmake:devel/boxed-cpp \
		${LOCALBASE}/lib/cmake/reflection-cpp/reflection-cpp-config.cmake:devel/reflection-cpp \
		${LOCALBASE}/share/cmake/Microsoft.GSL/Microsoft.GSLConfig.cmake:devel/microsoft-gsl \
		${LOCALBASE}/lib/cmake/range-v3/range-v3-config.cmake:devel/range-v3
LIB_DEPENDS=	libunicode.so:devel/libunicode-contour \
		libyaml-cpp.so:devel/yaml-cpp \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libssh2.so:security/libssh2 \
		libfontconfig.so:x11-fonts/fontconfig
TEST_DEPENDS=	${LOCALBASE}/lib/cmake/Catch2/Catch2Config.cmake:devel/catch2

USES=		cmake:testing desktop-file-utils gl pkgconfig qt:6 xorg

USE_GITHUB=	yes
GH_ACCOUNT=	contour-terminal

USE_XORG=	xcb
USE_GL=		gl opengl
USE_QT=		5compat base declarative multimedia tools:build

CMAKE_ON=		CONTOUR_INSTALL_TOOLS
CMAKE_TESTING_ON=	CONTOUR_TESTING

PORTDOCS=	README.md SECURITY.md TODO.md

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${ARCH} == i386
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src_crispy_read__selector.h
.endif

# FreeBSD 13 does not have tic in base, so we need one from ports
.if ${OPSYS} == FreeBSD && ${OSREL:R} == 13
BUILD_DEPENDS+=	tic:devel/ncurses
.endif

post-install:
	@${RM} -r ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/src/contour/shell-integration/shell-integration.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/contour/shell-integration/shell-integration.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/${PORTNAME}.fish
	${INSTALL_DATA} ${WRKSRC}/src/contour/shell-integration/shell-integration.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
