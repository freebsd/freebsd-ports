PORTNAME=	way-displays
DISTVERSION=	1.14.1
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Auto Manage Your Wayland Displays
WWW=		https://github.com/alex-courtis/way-displays

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libinotify.so:devel/libinotify \
		libudev.so:devel/libudev-devd \
		libyaml-cpp.so:devel/yaml-cpp \
		libwayland-client.so:graphics/wayland \
		libinput.so:x11/libinput
TEST_DEPENDS=	cmocka>0:sysutils/cmocka

USES=		compiler:c11 gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	alex-courtis
MAKEFILE=	GNUmakefile
MAKE_ENV=	VERSION="${DISTVERSIONFULL}"
MAKE_ARGS=	CC="${CC}" CXX="${CXX}" OFLAGS=
TEST_TARGET=	test
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		"@sample ${ETCDIR}/cfg.yaml.sample"

post-patch:
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},' \
		${WRKSRC}/src/cfg.c \
		${WRKSRC}/tst/tst-cfg.c

post-install:
# Let @sample handle default files under etc/
	@for f in ${STAGEDIR}${ETCDIR}/*; do \
		${MV} $$f $$f.sample; \
	done

.include <bsd.port.mk>
