PORTNAME=	darktile
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.11
PORTREVISION=	14
CATEGORIES=	x11

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Golang terminal emulator from scratch
WWW=		https://github.com/liamg/darktile

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		gl go:modules pkgconfig xorg
USE_GL=		gl
USE_XORG=	x11 xcursor xi xinerama xrandr xxf86vm

GO_MODULE=	github.com/liamg/darktile
GO_TARGET=	./cmd/darktile \
		./cmd/packfont

PLIST_FILES=	bin/${PORTNAME} \
		bin/packfont

.include <bsd.port.mk>
