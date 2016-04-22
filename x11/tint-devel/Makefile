# $FreeBSD$

PORTNAME=	tint2
PORTVERSION=	2.00.${DATE}
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://deponie.yamagi.org/freebsd/distfiles/tint/
PKGNAMESUFFIX=	-devel
DISTNAME=	tint2-devel-${DATE}

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Lightweight freedesktop-compliant panel (development version)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libImlib2.so:graphics/imlib2 \
		librsvg-2.so:graphics/librsvg2 \
		libstartup-notification-1.so:x11/startup-notification

CONFLICTS=	tint2-[0-9]*

IGNORE=		-devel version is older than x11/tint

USES=		alias cmake pkgconfig tar:xz
USE_GNOME=	glib20 gtk20 pango
USE_XORG=	xcomposite xdamage xinerama xrandr

CMAKE_ARGS=	-DENABLE_BATTERY:BOOL=ON -DMANDIR:PATH=man

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

DATE=	20150710

PORTEXAMPLES=	icon_and_text_1.tint2rc icon_and_text_2.tint2rc \
		icon_and_text_3.tint2rc icon_and_text_4.tint2rc \
		icon_only_1.tint2rc icon_only_2.tint2rc icon_only_3.tint2rc \
		icon_only_4.tint2rc icon_only_6.tint2rc icon_only_7.tint2rc \
		text_only_1.tint2rc text_only_2.tint2rc text_only_3.tint2rc \
		text_only_4.tint2rc text_only_5.tint2rc text_only_6.tint2rc tint2rc
PORTDOCS=	AUTHORS ChangeLog README.md

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tint2 ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/tint2-devel
	${INSTALL_DATA} ${WRKSRC}/default_icon.png ${STAGEDIR}${PREFIX}/share/tint2-devel
	${INSTALL_MAN} ${WRKSRC}/doc/tint2.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR}  ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/sample/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
