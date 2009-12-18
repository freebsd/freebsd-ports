# New ports collection makefile for:	avant-window-navigator
# Date created:		18 May 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	avant-window-navigator
PORTVERSION=	0.3.2.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://launchpadlibrarian.net/26374006/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Dock-like navigation bar

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg
LIB_DEPENDS=	wnck-1.22:${PORTSDIR}/x11-toolkits/libwnck \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 gtk20 pygtk2
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_XORG=	x11 xproto xcomposite xrender
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CPPFLAGS="-I${LOCALBASE}/include"
MAKE_JOBS_SAFE=	yes

AWN_DESKTOP?=	agnostic

.if ${AWN_DESKTOP} == "gnome"
USE_GNOME+=	gnomedesktop libgnomeui
CONFIGURE_ARGS+=	--with-desktop=gnome
PKGNAMESUFFIX=	-gnome
CONFLICTS=	${PORTNAME}-xfce4-[0-9]* ${PORTNAME}-[0-9]*
WITH_GCONF=	yes
.elif ${AWN_DESKTOP} == "xfce4"
OPTIONS=	GCONF "Use GConf to store configuration information" off
USE_XFCE+=	thunar
CONFIGURE_ARGS+=	--with-desktop=xfce4
PKGNAMESUFFIX=	-xfce4
CONFLICTS=	${PORTNAME}-gnome-[0-9]* ${PORTNAME}-[0-9]*
.else
# agnostic desktop
OPTIONS=	GCONF "Use GConf to store configuration information" off
CONFIGURE_ARGS+=	--with-desktop=agnostic
CONFLICTS=	${PORTNAME}-gnome-[0-9]* ${PORTNAME}-xfce4-[0-9]*
.endif

.include <bsd.port.options.mk>

.if defined(WITH_GCONF)
USE_GNOME+=	gconf2
GCONF_SCHEMAS=	awn.schemas awn-applets-shared.schemas
CONFIGURE_ARGS+=	--with-gconf
.else
CONFIGURE_ARGS+=	--without-gconf
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|#!/usr/bin/python|#!/usr/bin/env python|' \
		${WRKSRC}/awn-manager/awnManager.py.in \
		${WRKSRC}/awn-manager/awnManager.py
	@${REINPLACE_CMD} -e '1 s|bash|sh|' \
		${WRKSRC}/awn-manager/awn-launcher-editor.in

.include <bsd.port.post.mk>
