# $FreeBSD$

PORTNAME=	aminal
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	x11

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Golang terminal emulator from scratch

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gl go xorg
USE_GITHUB=	yes
GH_ACCOUNT=	liamg
GH_TUPLE=	BurntSushi:xgb:27f1227:xgb/vendor/github.com/BurntSushi/xgb \
		gen2brain:shm:6c18ff7:shm/vendor/github.com/gen2brain/shm
USE_GL=		gl
USE_XORG=	x11 xcursor xi xinerama xrandr xxf86vm

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

PORTSCOUT=	limit:^[0-9].*

post-patch: # https://github.com/liamg/aminal/issues/208
	@cd ${WRKSRC}/platform && \
		${CP} linuxLaunch.go freebsdLaunch.go && \
		${REINPLACE_CMD} 's|build linux|build freebsd|' freebsdLaunch.go

.include <bsd.port.mk>
