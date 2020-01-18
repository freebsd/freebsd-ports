# $FreeBSD$

PORTNAME=	caffeine-ng
DISTVERSION=	3.4.2
PORTREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@yandex.com
COMMENT=	Tray bar app to temporarily inhibit screensaver and sleep mode

LICENSE=	GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENCE
LICENSE_FILE_LGPL3+ =	${WRKSRC}/LGPL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
LIB_DEPENDS=	libappindicator3.so:devel/libappindicator \
		libnotify.so:devel/libnotify
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docopt>=0.6.2:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ewmh>=0.1.4:devel/py-ewmh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>=0.25:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.1.10:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.29.0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8-import-order>0:devel/py-flake8-import-order@${PY_FLAVOR}

USES=		desktop-file-utils gettext-tools gnome python:3.3+
USE_GNOME=	gdkpixbuf2 gtk30 pygobject3
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

GLIB_SCHEMAS=	net.launchpad.caffeine.gschema.xml
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.rst

REINPLACE_ARGS=	-i ""

SCHEMASDIR=	share/glib-2.0/schemas

post-patch:
	${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g; s|/etc|${LOCALBASE}/etc|g' \
		${WRKSRC}/setup.py \
		${WRKSRC}/share/applications/*.desktop

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SCHEMASDIR}
.for schema in ${GLIB_SCHEMAS}
	${INSTALL_DATA} ${WRKSRC}/${SCHEMASDIR}/${schema} ${STAGEDIR}${PREFIX}/${SCHEMASDIR}
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m tox

.include <bsd.port.mk>
