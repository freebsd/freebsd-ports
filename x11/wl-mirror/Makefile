PORTNAME=	wl-mirror
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.2
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

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_CMAKE_BOOL=	INSTALL_DOCUMENTATION
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

post-patch:
	@${ECHO_CMD} "${DISTVERSIONFULL}" >${WRKSRC}/version.txt
	@${REINPLACE_CMD} 's,/usr,${LOCALBASE},' ${WRKSRC}/CMakeLists.txt

pre-configure:
	@${TOUCH} ${WRKSRC_wlrproto}/.git

.include <bsd.port.mk>
