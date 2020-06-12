# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-terminal
PORTVERSION=	1.24.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the MATE Desktop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libpcre2-8.so:devel/pcre2

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pathfix perl5 pkgconfig \
		shebangfix tar:xz xorg
USE_XORG=	ice sm x11
USE_GNOME=	cairo dconf gdkpixbuf2 gtk30 intltool vte3
SHEBANG_FILES=	mate-terminal.wrapper
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.mate.terminal.gschema.xml

.include <bsd.port.mk>
