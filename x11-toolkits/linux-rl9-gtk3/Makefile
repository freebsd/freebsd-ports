PORTNAME=	gtk3
PORTVERSION=	3.24.31
DISTVERSIONSUFFIX=	-2.el9
PORTREVISION=	1
CATEGORIES=	x11-toolkits linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GTK+ library, version 3.X (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.gtk.org/

RUN_DEPENDS=	hicolor-icon-theme>0:misc/hicolor-icon-theme \
		adwaita-icon-theme>0:x11-themes/adwaita-icon-theme

USES=		cpe linux:rl9
CPE_VENDOR=	gnome
CPE_PRODUCT=	gtk
USE_LDCONFIG=	yes
USE_LINUX=	at-spi2-atk atk cairo-gobject dbuslibs fontconfig freetype gdkpixbuf2 \
		gnutls icu libepoxy libproxy librsvg2 libtracker-sparql \
		libxkbcommon pango wayland xorglibs
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${PORTNAME}-${PORTVERSION}${DISTVERSIONSUFFIX} \
		libstemmer-0-18.585svn.el9

DESCR=		${.CURDIR}/../${PORTNAME}0/pkg-descr

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
