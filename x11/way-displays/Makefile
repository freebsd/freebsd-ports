PORTNAME=	way-displays
DISTVERSION=	1.4.0
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	813843077c0c.patch:-p1 # https://github.com/alex-courtis/way-displays/pull/21
PATCHFILES+=	edeeb344a430.patch:-p1 # https://github.com/alex-courtis/way-displays/pull/21
PATCHFILES+=	d57fc203a043.patch:-p1 # https://github.com/alex-courtis/way-displays/pull/21

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Auto Manage Your Wayland Displays

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	https://github.com/alex-courtis/way-displays/issues/23

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libinotify.so:devel/libinotify \
		libudev.so:devel/libudev-devd \
		libyaml-cpp.so:devel/yaml-cpp \
		libwayland-client.so:graphics/wayland \
		libinput.so:x11/libinput

USES=		compiler:c11 gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	alex-courtis
MAKE_ENV=	VERSION="${DISTVERSIONFULL}"
MAKE_ARGS=	OFLAGS=
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
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
