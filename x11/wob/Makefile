PORTNAME=	wob
DISTVERSION=	0.16
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Lightweight overlay volume (or anything) bar for Wayland
WWW=		https://github.com/francma/wob

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.31:graphics/wayland-protocols
LIB_DEPENDS=	libinih.so:devel/inih \
		libwayland-client.so:graphics/wayland
TEST_DEPENDS=	cmocka>0:sysutils/cmocka

USES=		meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	francma
MESON_DISABLED=	seccomp systemd-unit-files tests
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz \
			share/man/man5/${PORTNAME}.ini.5.gz

post-patch:
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} 's,/etc,${PREFIX}&,' \
		${WRKSRC}/src/config.c \
		${WRKSRC}/${PORTNAME}.1.scd

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dtests=enabled"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
