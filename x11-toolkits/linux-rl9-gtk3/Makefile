PORTNAME=	gtk3
PORTVERSION=	3.24.31
DISTVERSIONSUFFIX=	-8.el9
PORTREVISION=	6
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
		gnutls icu libepoxy librsvg2 libstemmer libtracker-sparql \
		libxkbcommon pango wayland xorglibs
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}0/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
