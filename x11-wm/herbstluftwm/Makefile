PORTNAME=	herbstluftwm
DISTVERSION=	0.9.6
CATEGORIES=	x11-wm
MASTER_SITES=	https://herbstluftwm.org/tarballs/

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Manual tiling window manager for X11
WWW=		https://herbstluftwm.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asciidoc:textproc/asciidoc
LIB_DEPENDS=	libfreetype.so:print/freetype2
RUN_DEPENDS=	bash>0:shells/bash \
		dzen2>0:x11/dzen2

USES=		cmake compiler:c++11-lang gnome localbase:ldflags pkgconfig \
		shebangfix xorg
USE_GNOME=	glib20
USE_XORG=	x11 xext xfixes xft xinerama xrandr xrender

SHEBANG_FILES=	doc/gendoc.py scripts/*.sh share/*.sh

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's,$${DOCDIR}/examples,${EXAMPLESDIR},' ${WRKSRC}/CMakeLists.txt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/herbst*

.include <bsd.port.mk>
