PORTNAME=	herbstluftwm
DISTVERSION=	0.9.5
CATEGORIES=	x11-wm
MASTER_SITES=	https://herbstluftwm.org/tarballs/

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Manual tiling window manager for X11
WWW=		https://herbstluftwm.org/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	asciidoc:textproc/asciidoc
LIB_DEPENDS+=	libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lang gnome \
		localbase:ldflags pkgconfig shebangfix xorg
USE_GNOME=	glib20
USE_XORG=	x11 xext xfixes xft xinerama xrandr xrender

SHEBANG_FILES=	doc/gendoc.py scripts/*.sh share/*.sh

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes
DOCS_USES+=	python:build
DOCS_CMAKE_BOOL+=	WITH_DOCUMENTATION

DOCS_VARS=	binary_alias=python3=${PYTHON_CMD}

.include <bsd.port.options.mk>

post-patch-EXAMPLES-on:
	@${REINPLACE_CMD} -e 's,$${DOCDIR}/examples,${EXAMPLESDIR},' ${WRKSRC}/CMakeLists.txt

post-patch-EXAMPLES-off:
	@${REINPLACE_CMD} -e '\@$${DOCDIR}/examples@d' ${WRKSRC}/CMakeLists.txt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/herbst*

.include <bsd.port.mk>
