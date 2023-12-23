PORTNAME=	xfce4-taskmanager
PORTVERSION=	1.5.6
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Task manager for the Xfce desktop
WWW=		https://goodies.xfce.org/projects/applications/xfce4-taskmanager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		gettext-tools gmake gnome localbase pkgconfig tar:bzip2 \
		xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool libwnck3
USE_XFCE=	libmenu xfconf
USE_XORG=	ice sm x11 xmu xt

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-silent-rules --disable-gksu --enable-wnck3

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
