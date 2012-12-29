# New ports collection makefile for:	zenity
# Date created:				01 Mar 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#   $MCom: ports/x11/zenity/Makefile,v 1.111 2010/11/16 10:25:21 kwm Exp $
#

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

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20 gnomedocutils intlhack
USE_BZIP2=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

MAN1=		zenity.1

CONFLICTS=	gtkada-1.2.*

OPTIONS=	NOTIFY "Enable libnotify support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=		notify.4:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=	--enable-libnotify
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

.include <bsd.port.post.mk>
