PORTNAME=	xfce4-panel-profiles
PORTVERSION=	1.1.1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's panel multiple layouts manager
WWW=		https://docs.xfce.org/apps/xfce4-panel-profiles/start

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=7.0.0:sysutils/py-psutil@${PY_FLAVOR}

USES=		gettext-tools gnome meson pkgconfig python shebangfix tar:xz \
		xfce
USE_GNOME=	glib20 gtk30 pygobject3
USE_XFCE=	libmenu panel

SHEBANG_FILES=	xfce4-panel-profiles/panelconfig.py \
		xfce4-panel-profiles/xfce4-panel-profiles.py
BINARY_ALIAS=	python3=${PYTHON_CMD}
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
