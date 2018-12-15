# $FreeBSD$

PORTNAME=	aminal
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.12
CATEGORIES=	x11

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Golang terminal emulator from scratch

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/LICENSE

BUILD_DEPENDS=	go:lang/go

USES=		gl
USE_GITHUB=	nodefault # the main code is in GH_TUPLE
GH_ACCOUNT=	liamg
GH_TUPLE=	liamg:aminal:${DISTVERSIONFULL}:main/src/github.com/liamg/aminal
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}
USE_GL=		gl
USE_XORG=	x11 xcursor xi xinerama xrandr xxf86vm

MAKE_ENV=	CGO_CFLAGS="-I${LOCALBASE}/include" CGO_LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go install ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
