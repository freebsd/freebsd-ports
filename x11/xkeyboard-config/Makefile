PORTNAME=	xkeyboard-config
DISTVERSION=	2.49
CATEGORIES=	x11
MASTER_SITES=	https://gitlab.freedesktop.org/${PORTNAME}/${PORTNAME}/-/archive/${PORTNAME}-${DISTVERSION}/
DISTNAME=	${PORTNAME}-${PORTNAME}-${DISTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Keyboard Configuration Database
WWW=		https://xkeyboard-config.freedesktop.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	gawk:lang/gawk

USES=		gnome localbase meson pathfix perl5 python:build tar:bz2

NO_ARCH=	yes
USE_GNOME=	libxslt:build
USE_PERL5=	build

MESON_ARGS=	-Dxorg-rules-symlinks=true

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=	ETERSOFT NLS X11
OPTIONS_DEFAULT=X11
NLS_USES=	gettext-tools iconv
NLS_MESON_TRUE=	nls
ETERSOFT_DESC=	Add pre-1918 Russian letters to typographic layout
OPTIONS_SUB=	yes

ETERSOFT_EXTRA_PATCHES=	${FILESDIR}/etersoft-patch-symbols-typo
X11_BUILD_DEPENDS=	xkbcomp:x11/xkbcomp
X11_DESC=		XKB keyboard description compiler support

.include <bsd.port.mk>
