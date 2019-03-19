# Created by: DaJoob
# $FreeBSD$

PORTNAME=	xfce4-taskmanager
PORTVERSION=	1.2.2
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

USES=		gettext-tools gmake gnome localbase pkgconfig tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool libwnck3
USE_XORG=	ice sm x11 xmu xt

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ARGS+=	--disable-silent-rules --disable-gksu \
			--enable-wnck3 --enable-wnck --disable-gtk2

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
