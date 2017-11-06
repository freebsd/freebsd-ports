# Created by: DaJoob
# $FreeBSD$

PORTNAME=	xfce4-taskmanager
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Task manager for the Xfce desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
	libfreetype.so:print/freetype2

GNU_CONFIGURE=	yes
USES=		gettext gmake localbase pkgconfig tar:bzip2
USE_GNOME=	gtk20 glib20 cairo gdkpixbuf2 intltool libwnck
USE_XORG=	ice sm x11 xmu xt

CONFIGURE_ARGS+=	--disable-gksu \
	--disable-gtk3 --disable-wnck3 \
	--enable-wnck

.include <bsd.port.mk>
