# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11/libgnomekbd/Makefile,v 1.48 2010/09/28 08:01:11 kwm Exp $

PORTNAME=	libgnomekbd
PORTVERSION=	2.32.0
PORTREVISION=	4
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyboard shared library

LIB_DEPENDS=	libxklavier.so:${PORTSDIR}/x11/libxklavier

GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gconf2
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	desktop_gnome_peripherals_keyboard_xkb.schemas

#post-patch:
#	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
#	    	's|-Werror||g'

.include <bsd.port.mk>
