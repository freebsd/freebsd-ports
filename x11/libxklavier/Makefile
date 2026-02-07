PORTNAME=	libxklavier
PORTVERSION=	5.3
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Utility library to make XKB stuff easier
WWW=		https://gswitchit.sourceforge.net/

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes
RUN_DEPENDS=	xkbcomp:x11/xkbcomp \
		iso-codes>=0:misc/iso-codes

USES=		gmake gnome libtool pathfix pkgconfig tar:xz xorg
USE_XORG=	x11 xkbfile
USE_GNOME=	libxml2 glib20 introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-xkb-base=${LOCALBASE}/share/X11/xkb \
		--with-xkb-bin-base=${LOCALBASE}/bin \
		--with-xmodmap-base=${LOCALBASE}/share/xmodmap \
		--disable-gtk-doc \
		--with-html-dir=${GNOME_HTML_DIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
