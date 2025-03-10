PORTNAME=	keyboard
PORTVERSION=	0.4.0
CATEGORIES=	x11
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Keyboard/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Keyboard-${PORTVERSION}

MAINTAINER=	khorben@defora.org
COMMENT=	DeforaOS desktop virtual keyboard
WWW=		https://www.defora.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libDesktop.so:x11/deforaos-libdesktop \
		libSystem.so:devel/deforaos-libsystem \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		desktop-file-utils gnome pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_XORG=	x11 xtst

MAKE_ARGS+=	PREFIX=${PREFIX}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

NLS_USES=	gettext

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|data doc include|data include|' \
	${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's|include po src|include src|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/keyboardctl \
		${STAGEDIR}${PREFIX}/bin/keyboard \
		${STAGEDIR}${PREFIX}/lib/Desktop/widget/keyboard.so

.include <bsd.port.mk>
