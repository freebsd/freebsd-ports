PORTNAME=	way-displays
DISTVERSION=	1.3.0
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	90081b314a75.patch:-p1 # https://github.com/alex-courtis/way-displays/pull/21

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Auto Manage Your Wayland Displays

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libinotify.so:devel/libinotify \
		libudev.so:devel/libudev-devd \
		libyaml-cpp.so:devel/yaml-cpp \
		libwayland-client.so:graphics/wayland \
		libinput.so:x11/libinput

USES=		compiler:c11 gmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	alex-courtis
MAKE_ENV=	VERSION="${DISTVERSIONFULL}"
MAKE_ARGS=	CC="${CC}" CXX="${CXX}" OFLAGS=
CFLAGS+=	-isystem${LOCALBASE}/include/libepoll-shim
LDFLAGS+=	-lepoll-shim -linotify
PLIST_FILES=	bin/${PORTNAME} \
		"@sample ${ETCDIR}/cfg.yaml.sample"

post-patch:
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},' ${WRKSRC}/src/cfg.cpp

post-install:
# Let @sample handle default files under etc/
	@for f in ${STAGEDIR}${ETCDIR}/*; do \
		${MV} $$f $$f.sample; \
	done

.include <bsd.port.mk>
