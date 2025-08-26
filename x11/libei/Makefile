PORTNAME=	libei
DISTVERSION=	1.5.0
CATEGORIES=	x11

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	4f11112be0c0.patch:-p1 # https://gitlab.freedesktop.org/libinput/libei/-/merge_requests/357

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Library for Emulated Input
WWW=		https://gitlab.freedesktop.org/libinput/libei

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		${PYTHON_PKGNAMEPREFIX}attrs>0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR}
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libevdev.so:devel/libevdev
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dbusmock>0:devel/py-python-dbusmock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}structlog>0:devel/py-structlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		compiler:c11 localbase meson pkgconfig python:build
USE_GITHUB=	nodefault
USE_GITLAB=	yes
USE_LDCONFIG=	yes
GH_TUPLE=	nemequ:munit:v0.2.0-38-gfbbdf14:munit/subprojects/munit
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	libinput
BINARY_ALIAS=	python3=${PYTHON_CMD}
MESON_ARGS=	-Dsd-bus-provider=basu -Dtests=disabled
PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	BASU
OPTIONS_DEFAULT=BASU
OPTIONS_SUB=	yes

BASU_DESC=		XDG RemoteDesktop portal via basu
BASU_LIB_DEPENDS=	libbasu.so:devel/basu
BASU_MESON_ENABLED=	liboeffis

.ifdef GH_TUPLE
post-configure:
	@${REINPLACE_CMD} 's/meson install/& \
		--skip-subprojects/' ${BUILD_WRKSRC}/build.ninja
.endif

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dtests=enabled"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}StrEnum>0:devel/py-strenum@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
