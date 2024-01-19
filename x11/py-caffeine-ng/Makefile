PORTNAME=	caffeine-ng
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.0
DISTVERSIONSUFFIX=	-0-g5027f55
CATEGORIES=	x11 python
MASTER_SITES=	https://codeberg.org/WhyNotHugo/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Tray bar app to temporarily inhibit screensaver and sleep mode
WWW=		https://codeberg.org/WhyNotHugo/caffeine-ng

LICENSE=	GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENCE
LICENSE_FILE_LGPL3+ =	${WRKSRC}/LGPL

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ewmh>0:devel/py-ewmh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pulsectl>0:audio/py-pulsectl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		scdoc:textproc/scdoc
LIB_DEPENDS=	libayatana-appindicator3.so:devel/libayatana-appindicator \
		libnotify.so:devel/libnotify
RUN_DEPENDS=	${PY_DEPENDS}

USES=		gettext-tools gnome meson pkgconfig python
USE_GNOME=	gdkpixbuf2 gtk30 pygobject3
GLIB_SCHEMAS=	net.launchpad.caffeine.gschema.xml

BINARY_ALIAS=	python3=${PYTHON_CMD}
NO_ARCH=	yes

PORTDOCS=	CHANGELOG.rst README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e "s|/etc|${LOCALBASE}/etc|g; \
		s|python.full_path()|'${PYTHON_CMD}'|g" ${WRKSRC}/meson.build

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
