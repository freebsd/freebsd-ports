PORTNAME=	xkeyboard-config
DISTVERSION=	2.41
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/data/${PORTNAME}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Keyboard Configuration Database
WWW=		https://freedesktop.org/wiki/Software/XKeyboardConfig/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	gawk:lang/gawk

USES=		meson gnome localbase pathfix perl5 python:build \
		shebangfix tar:xz

NO_ARCH=	yes
USE_GNOME=	libxslt:build
USE_PERL5=	build
SHEBANG_FILES=	rules/merge.py \
		rules/compat/map-variants.py

MESON_ARGS=	-Dxkb-base=${PREFIX}/share/X11/xkb \
		-Dxorg-rules-symlinks=true

OPTIONS_DEFINE=	ETERSOFT NLS X11
OPTIONS_DEFAULT=X11
NLS_USES=	gettext-tools iconv
NLS_MESON_TRUE=	nls
ETERSOFT_DESC=	Add pre-1918 Russian letters to typographic layout
OPTIONS_SUB=	yes

ETERSOFT_EXTRA_PATCHES=	${FILESDIR}/etersoft-patch-symbols-typo
X11_BUILD_DEPENDS=	xkbcomp:x11/xkbcomp
X11_DESC=		XKB keyboard description compiler support

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}/var/lib/xkb
	@${LN} -sf /var/lib/xkb ${STAGEDIR}${PREFIX}/share/X11/xkb/compiled

.include <bsd.port.mk>
