PORTNAME=	wl-mirror
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.3
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple Wayland output mirror client
WWW=		https://github.com/Ferdi265/wl-mirror

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libwayland-egl.so:graphics/wayland

USES=		cmake gl pkgconfig
USE_GITHUB=	yes
USE_GITLAB=	nodefault
USE_GL=		glesv2 egl
GH_ACCOUNT=	Ferdi265
GL_TUPLE=	https://gitlab.freedesktop.org:wlroots:wlr-protocols:4264185:wlrproto/proto/wlr-protocols
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	CSD MANPAGES OPENGL
OPTIONS_DEFAULT=CSD MANPAGES OPENGL

CSD_DESC=		Client-side decorations via libdecor
CSD_LIB_DEPENDS=	libdecor-0.so:x11-toolkits/libdecor
CSD_CMAKE_BOOL=		WITH_LIBDECOR

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_CMAKE_BOOL=	INSTALL_DOCUMENTATION
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

OPENGL_LIB_DEPENDS=	libdrm.so:graphics/libdrm
OPENGL_USE=		GL=gbm
OPENGL_CMAKE_BOOL=	WITH_GBM

post-patch:
	@${ECHO_CMD} "${DISTVERSIONFULL}" >${WRKSRC}/version.txt
	@${REINPLACE_CMD} 's,/usr,${LOCALBASE},' ${WRKSRC}/CMakeLists.txt

pre-configure:
	@${TOUCH} ${WRKSRC_wlrproto}/.git

.include <bsd.port.mk>
