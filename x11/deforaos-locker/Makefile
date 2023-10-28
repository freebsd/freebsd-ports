PORTNAME=	locker
PORTVERSION=	0.4.2
CATEGORIES=	x11
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Locker/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Locker-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS desktop screensaver
WWW=		https://www.defora.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/Panel.pc:x11-wm/deforaos-panel
LIB_DEPENDS=	libDesktop.so:x11/deforaos-libdesktop \
		libSystem.so:devel/deforaos-libsystem \
		libharfbuzz.so:print/harfbuzz \
		libXss.so:x11/libXScrnSaver

USES=		gnome pkgconfig xorg desktop-file-utils
USE_GNOME=	gtk30 cairo gdkpixbuf2
USE_XORG=	x11 xext
MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ARGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man
LDFLAGS+=	-lXext

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=		gettext
DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
			gtkdoc-mkhtml:textproc/gtk-doc

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
