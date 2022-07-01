PORTNAME=	wl-mirror
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.2
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple Wayland output mirror client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_12=	ld: error: undefined symbol: memfd_create

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-egl.so:graphics/wayland

USES=		cmake gl localbase:ldflags
USE_GITHUB=	yes
USE_GITLAB=	nodefault
USE_GL=		glesv2 egl
GH_ACCOUNT=	Ferdi265
GL_TUPLE=	https://gitlab.freedesktop.org:wlroots:wlr-protocols:0c7437e2b600382f0be33949c4e244b2a3702fcb:wlrproto/proto/wlr-protocols
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${ECHO_CMD} "${DISTVERSIONFULL}" >${WRKSRC}/version.txt
	@${REINPLACE_CMD} 's,/usr,${LOCALBASE},' ${WRKSRC}/CMakeLists.txt

pre-configure:
	@${TOUCH} ${WRKSRC_wlrproto}/.git

.include <bsd.port.mk>
