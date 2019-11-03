# $FreeBSD$

PORTNAME=	xkeyboard-config
PORTVERSION=	2.27
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/${XORG_CAT}/${PORTNAME}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Keyboard Configuration Database

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xkbcomp:x11/xkbcomp

USES=		gmake gnome localbase pathfix perl5 xorg-cat:data

NO_ARCH=	yes
USE_GNOME=	libxslt:build
USE_PERL5=	build

CONFIGURE_ARGS=	--with-xkb-base=${PREFIX}/share/X11/xkb \
		--with-xkb-rules-symlink=xorg

OPTIONS_DEFINE=	ETERSOFT
ETERSOFT_DESC=	Add pre-1918 Russian letters to typographic layout
ETERSOFT_EXTRA_PATCHES=	${FILESDIR}/etersoft-patch-symbols-typo

.include <bsd.port.options.mk>

# !nls case doesn't work correctly, comment it out.
#.if ${PORT_OPTIONS:MNLS}
USES+=		gettext-tools iconv
PLIST_SUB+=	NLS=""
#.else
#CONFIGURE_ARGS+=--disable-nls
#PLIST_SUB+=	NLS="@comment "
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' -e 's|==|=|g' \
		${WRKSRC}/rules/merge.sh

post-install:
	@${MKDIR} ${STAGEDIR}/var/lib/xkb
	@${LN} -sf /var/lib/xkb ${STAGEDIR}${PREFIX}/share/X11/xkb/compiled

.include <bsd.port.mk>
