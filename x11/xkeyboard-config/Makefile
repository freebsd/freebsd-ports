# $FreeBSD$

PORTNAME=	xkeyboard-config
PORTVERSION=	2.8
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Keyboard Configuration Database
MASTER_SITE_SUBDIR=	individual/${XORG_CAT}/${PORTNAME}

LICENSE=	MIT

BUILD_DEPENDS=	xkbcomp:${PORTSDIR}/x11/xkbcomp \
		xsltproc:${PORTSDIR}/textproc/libxslt
XORG_CAT=	data

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	intlhack
USES=		pathfix
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

CONFIGURE_ARGS=	--with-xkb-base=${PREFIX}/share/X11/xkb \
		--with-xkb-rules-symlink=xorg
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN7=		xkeyboard-config.7

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' -e 's|==|=|g' \
		${WRKSRC}/rules/merge.sh

post-install:
	${MKDIR} /var/lib/xkb
	${LN} -sf /var/lib/xkb ${PREFIX}/share/X11/xkb/compiled

.include <bsd.port.mk>
