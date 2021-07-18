PORTNAME=	xkeyboard-config
PORTVERSION=	2.32
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/data/${PORTNAME}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Keyboard Configuration Database

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake gnome localbase pathfix perl5 python:3.5+,build \
		shebangfix xorg-cat:data

NO_ARCH=	yes
USE_GNOME=	libxslt:build
USE_PERL5=	build
SHEBANG_FILES=	rules/merge.py \
		rules/compat/map-variants.py

CONFIGURE_ARGS=	--with-xkb-base=${PREFIX}/share/X11/xkb \
		--with-xkb-rules-symlink=xorg

OPTIONS_DEFINE=	ETERSOFT NLS X11
OPTIONS_DEFAULT=X11
ETERSOFT_DESC=	Add pre-1918 Russian letters to typographic layout
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-tools iconv
ETERSOFT_EXTRA_PATCHES=	${FILESDIR}/etersoft-patch-symbols-typo
X11_BUILD_DEPENDS=	xkbcomp:x11/xkbcomp
X11_CONFIGURE_OFF=	--disable-runtime-deps
X11_DESC=		XKB keyboard description compiler support

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}/var/lib/xkb
	@${LN} -sf /var/lib/xkb ${STAGEDIR}${PREFIX}/share/X11/xkb/compiled

.include <bsd.port.mk>
