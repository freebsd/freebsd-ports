PORTNAME=	xdgmenumaker
DISTVERSION=	2.4
CATEGORIES=	x11-wm python

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Generate XDG menus for various window managers
WWW=		https://github.com/gapan/xdgmenumaker

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	txt2tags:textproc/txt2tags
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>=0:devel/py-xdg@${PY_FLAVOR}
TEST_DEPENDS:=	${RUN_DEPENDS}

USES=		display:test gnome python:run shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	gapan
USE_GNOME=	gtk30 pygobject3
SHEBANG_FILES=	src/${PORTNAME}

ALL_TARGET=	man
TEST_ENV=	PYTHON=${PYTHON_CMD}
TEST_TARGET=	test

NO_ARCH=	yes

post-patch:
# This should have improved locale-specific tests, but 10 out of 24 still fail
# (note that it is normal for tests that produce menus with icons to fail as
# they expect the exact same icon theme and applications the author is using).
	@${REINPLACE_CMD} -e 's,utf8,UTF-8,' ${WRKSRC}/tests/Makefile

.include <bsd.port.mk>
