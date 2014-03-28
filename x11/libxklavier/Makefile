# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/libxklavier/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libxklavier
PORTVERSION=	5.2.1
PORTEPOCH=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Utility library to make XKB stuff easier

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
RUN_DEPENDS=	xkbcomp:${PORTSDIR}/x11/xkbcomp \
    		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_XORG=	x11 xkbfile
USES=		gmake libtool pathfix pkgconfig tar:xz
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

PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxklavier.so.*

.include <bsd.port.mk>
