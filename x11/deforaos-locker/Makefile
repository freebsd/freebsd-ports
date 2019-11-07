# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	locker
PORTVERSION=	0.4.0
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/4424/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Locker-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS desktop screensaver

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libDesktop.so:x11/deforaos-libdesktop \
		libSystem.so:devel/deforaos-libsystem \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libXss.so:x11/libXScrnSaver

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/Panel.pc:x11/deforaos-panel

USES=		desktop-file-utils gnome pkgconfig xorg
USE_GNOME=	gtk20 cairo gdkpixbuf2
USE_XORG=	x11 xext
MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man
LDFLAGS+=	-lXext

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=		gettext
DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

post-patch:
	${REINPLACE_CMD} 's|-Wl,-pie||g' \
		${WRKSRC}/tests/Makefile \
		${WRKSRC}/tools/Makefile \
		${WRKSRC}/src/Makefile

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|data doc include|data include|' \
		${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's|include po src|include src|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/lib/Locker/auth/* \
		${STAGEDIR}${PREFIX}/lib/Locker/plugins/* \
		${STAGEDIR}${PREFIX}/lib/Locker/demos/*

.include <bsd.port.mk>
