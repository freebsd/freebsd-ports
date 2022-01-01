PORTNAME=	wl-mirror
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple Wayland output mirror client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-egl.so:graphics/wayland

USES=		cmake gl localbase:ldflags
USE_GITHUB=	yes
USE_GITLAB=	nodefault
USE_GL=		glesv2 egl
GH_ACCOUNT=	Ferdi265
GL_TUPLE=	https://gitlab.freedesktop.org:wlroots:wlr-protocols:d998ee6fc64ea7e066014023653d1271b7702c09:wlrproto/proto/wlr-protocols
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} 's,/usr,${LOCALBASE},' ${WRKSRC}/CMakeLists.txt

pre-configure:
	@${TOUCH} ${WRKSRC_wlrproto}/.git

.include <bsd.port.mk>
