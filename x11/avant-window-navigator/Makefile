# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	avant-window-navigator
PORTVERSION=	0.3.2.1
PORTREVISION?=	9
CATEGORIES=	x11
MASTER_SITES=	http://launchpadlibrarian.net/26374006/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dock-like navigation bar

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg
LIB_DEPENDS=	wnck-1:${PORTSDIR}/x11-toolkits/libwnck \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 gtk20 pygtk2
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build
INSTALLS_ICONS=	yes
USE_XORG=	x11 xproto xcomposite xrender
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
MAKE_JOBS_SAFE=	yes

AWN_DESKTOP?=	agnostic

.if ${AWN_DESKTOP} == "gnome"
USE_GNOME+=	gnomedesktop libgnomeui
CONFIGURE_ARGS+=	--with-desktop=gnome
PKGNAMESUFFIX=	-gnome
CONFLICTS=	${PORTNAME}-xfce4-[0-9]* ${PORTNAME}-[0-9]*
WITH_GCONF=	yes
.elif ${AWN_DESKTOP} == "xfce4"
OPTIONS_DEFINE=	GCONF
USE_XFCE+=	thunar
CONFIGURE_ARGS+=	--with-desktop=xfce4
PKGNAMESUFFIX=	-xfce4
CONFLICTS=	${PORTNAME}-gnome-[0-9]* ${PORTNAME}-[0-9]*
.else
# agnostic desktop
OPTIONS_DEFINE=	GCONF
CONFIGURE_ARGS+=	--with-desktop=agnostic
CONFLICTS=	${PORTNAME}-gnome-[0-9]* ${PORTNAME}-xfce4-[0-9]*
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGCONF}
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
