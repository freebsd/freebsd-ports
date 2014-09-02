# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11/yelp/Makefile,v 1.171 2012/10/01 16:19:07 kwm Exp $

PORTNAME=	yelp
PORTVERSION=	2.30.2
PORTREVISION=	9
CATEGORIES=	x11 gnome
MASTER_SITES=	LOCAL/kwm
DISTNAME=	${PORTNAME}-webkit-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Help browser for the GNOME 2 desktop

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2 \
		librarian.so:${PORTSDIR}/textproc/rarian

CONFLICTS=	yelp-3.[0-9]*

USES=		desktop-file-utils gettext gmake pathfix pkgconfig tar:bzip2
USE_XORG=	ice
USE_GNOME=	gnomeprefix intlhack gconf2 gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib \
		-fstack-protector

GCONF_SCHEMAS=	yelp.schemas

post-extract:
	${RM} -f ${WRKSRC}/data/yelp.schemas

post-patch:
	@${REINPLACE_CMD} -e 's,[-/]unstable,,' \
		-e 's/ --define-variable=includetype=unstable//' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} '/g_thread_init/d' ${WRKSRC}/src/yelp-main.c

.include <bsd.port.mk>
