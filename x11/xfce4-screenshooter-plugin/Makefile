# Created by: Martin Wilke (miwi@FreeBSD.org)

PORTNAME=	xfce4-screenshooter-plugin
PORTVERSION=	1.9.9
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/apps
DISTNAME=	xfce4-screenshooter-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application and panel plugin to take screenshots

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_CSTD=	c99
USE_GNOME=	cairo glib20 gtk30 intltool libxml2
USE_XFCE=	panel
USE_XORG=	ice sm x11 xfixes xext

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
