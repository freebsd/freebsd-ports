# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avant-window-navigator
PORTVERSION=	0.3.2.1
PORTREVISION?=	11
CATEGORIES=	x11
MASTER_SITES=	http://launchpadlibrarian.net/26374006/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dock-like navigation bar

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Fails to build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg
LIB_DEPENDS=	libwnck-1.so:${PORTSDIR}/x11-toolkits/libwnck \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pathfix pkgconfig python
USE_GNOME=	glib20 gtk20 pygtk2
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_XORG=	x11 xproto xcomposite xrender
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

AWN_DESKTOP?=	agnostic

.if ${AWN_DESKTOP} == "xfce4"
OPTIONS_DEFINE=	GCONF
USE_XFCE+=	thunar
CONFIGURE_ARGS+=	--with-desktop=xfce4
CONFLICTS=	${PORTNAME}-gnome-[0-9]* ${PORTNAME}-[0-9]*
PKGNAMESUFFIX=	-xfce4
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

post-patch:
	@${REINPLACE_CMD} '/^awn_applet_activation_LDADD =/s/=/= -lgmodule-2.0/' \
		${WRKSRC}/awn-applet-activation/Makefile.in
	@${REINPLACE_CMD} -e 's|#!/usr/bin/python|#!/usr/bin/env python|' \
		${WRKSRC}/awn-manager/awnManager.py.in \
		${WRKSRC}/awn-manager/awnManager.py
	@${REINPLACE_CMD} -e '1 s|bash|sh|' \
		${WRKSRC}/awn-manager/awn-launcher-editor.in
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/libawn/egg/eggchecksum.h \
		${WRKSRC}/libawn/awn-config-client-shared.c \
		${WRKSRC}/libawn/awn-config-client-gconf.c
	@${REINPLACE_CMD} -e 's|glib/gutils.h>|glib.h>|g' \
		${WRKSRC}/libawn/awn-config-client-gkeyfile.c
	@${REINPLACE_CMD} '/^avant_window_navigator_LDADD =/s/=/= -ldbus-glib-1/' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
