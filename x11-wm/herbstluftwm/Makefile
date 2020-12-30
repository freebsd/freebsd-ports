# $FreeBSD$

PORTNAME=	herbstluftwm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
CATEGORIES=	x11-wm

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Manual tiling window manager for X11

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	asciidoc:textproc/asciidoc

USES=		cmake compiler:c++11-lang gnome pkgconfig shebangfix xorg
USE_GITHUB=	yes
USE_GNOME=	glib20
USE_XORG=	x11 xext xinerama xrandr

SHEBANG_FILES=	doc/gendoc.py scripts/*.sh share/*.sh

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCS_USES+=	python:3.5+,build
DOCS_CMAKE_BOOL+=	WITH_DOCUMENTATION
OPTIONS_SUB=	yes

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-patch-EXAMPLES-on:
	@${REINPLACE_CMD} -e 's,$${DOCDIR}/examples,${EXAMPLESDIR},' ${WRKSRC}/CMakeLists.txt

post-patch-EXAMPLES-off:
	@${REINPLACE_CMD} -e '\@$${DOCDIR}/examples@d' ${WRKSRC}/CMakeLists.txt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/herbst*

.include <bsd.port.mk>
