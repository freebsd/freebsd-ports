# $FreeBSD$

PORTNAME=	herbstluftwm
PORTVERSION=	0.8.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://herbstluftwm.org/tarballs/

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Manual tiling window manager for X11

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	asciidoc:textproc/asciidoc

USES=		cmake compiler:c++11-lang gnome pkgconfig shebangfix xorg
USE_GNOME=	glib20
USE_XORG=	x11 xext xinerama xrandr

SHEBANG_FILES=	scripts/*.sh share/*.sh

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCS_CMAKE_ON=	WITH_DOCUMENTATION
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
