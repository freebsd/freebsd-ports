# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11/zenity/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	zenity
PORTVERSION=	2.32.1
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Display GNOME dialogs from the command line

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian
RUN_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian

NO_STAGE=	yes
USE_GNOME=	gnomeprefix gtk20 gnomedocutils intlhack
USE_BZIP2=	yes
USES=		gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-lintl ${PTHREAD_LIBS}"

MAN1=		zenity.1

CONFLICTS=	gtkada-1.2.*

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=		notify:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=	--enable-libnotify
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

.include <bsd.port.mk>
