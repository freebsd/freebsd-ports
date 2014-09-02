# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports/x11-wm/mutter/Makefile,v 1.14 2010/06/29 21:14:07 kwm Exp $

PORTNAME=	mutter
PORTVERSION=	2.31.2
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window and compositing manager based on Clutter

BUILD_DEPENDS=	zenity:${PORTSDIR}/x11/zenity
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libclutter-glx-1.0.so:${PORTSDIR}/graphics/clutter \
		libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra
RUN_DEPENDS=	zenity:${PORTSDIR}/x11/zenity

USE_XORG=	x11 xext xrandr xcomposite xcursor xinerama ice sm
USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	gnomeprefix intlhack gtk20 gconf2
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	mutter.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
	    	${WRKSRC}/configure
	@${REINPLACE_CMD} '/^mutter_LDADD =/s/$$/ -lgmodule-2.0/' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
