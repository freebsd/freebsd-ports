# New ports collection makefile for:	xfwm4
# Date created:		August 14, 2002
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-wm
PORTVERSION=	4.6.1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DISTNAME=	xfwm4-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 window manager

CONFIGURE_ARGS=	--enable-xinerama
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv libutil libgui panel xfconf

OPTIONS=	COMPOSITE	"Support the experimental X11 Composite extension"	on \
		STARTUP 	"Enable startup notification support"			on \
		REVMOUSE	"Reverse mouse workspace changing direction"		off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_COMPOSITE)
CONFIGURE_ARGS+=--enable-compositor
.else
CONFIGURE_ARGS+=--disable-compositor
.endif

.if !defined(WITHOUT_STARTUP)
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

.if defined(WITH_REVMOUSE)
EXTRA_PATCHES=  ${FILESDIR}/extrapatch-src__events.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\(#define ShapeInput 2\);|\1|' \
		${WRKSRC}/src/frame.c

.include <bsd.port.post.mk>
