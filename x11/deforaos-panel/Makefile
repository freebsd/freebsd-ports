# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deforaos-panel
PORTVERSION=	0.3.6
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/4417/
DISTNAME=	Panel-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS desktop panel

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libDesktop.so:x11/deforaos-libdesktop \
		libSystem.so:devel/deforaos-libsystem \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
BUILD_DEPENDS=	browser:x11-fm/deforaos-browser
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme \
		sudo:security/sudo

USES=		gnome pkgconfig xorg
USE_GNOME=	gtk20 cairo
USE_XORG=	x11
INSTALLS_ICONS=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}
USE_LDCONFIG=	yes

MAKE_ENV=	MANDIR=${STAGEDIR}${MANPREFIX}/man

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|data doc include|data include|' \
	${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's|include po src|include src|' \
		${WRKSRC}/Makefile

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		${WRKSRC}/src/panel.c
	${REINPLACE_CMD} 's|-Wl,-pie||g' \
		${WRKSRC}/tools/Makefile \
		${WRKSRC}/src/Makefile \
		${WRKSRC}/tests/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/lib/Panel/applets/* \
		${STAGEDIR}${PREFIX}/lib/libPanel.so.0.0

.include <bsd.port.mk>
