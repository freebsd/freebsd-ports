PORTNAME=	verve-plugin
PORTVERSION=	2.1.0
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
PKGNAMEPREFIX=	xfce4-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Command line plugin for the Xfce Desktop
WWW=		https://docs.xfce.org/panel-plugins/xfce4-verve-plugin/start

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce
USE_GNOME=	glib20 gtk30
USE_XFCE=	libmenu panel

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
