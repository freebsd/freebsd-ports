# $FreeBSD$

PORTNAME=	guake
PORTVERSION=	0.4.4.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://distfiles.gentoo.org/distfiles/ \
		http://nivit.altervista.org/FreeBSD/ports/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Dropdown terminal made for the GNOME desktop

LICENSE=	GPLv2

BUILD_DEPENDS=	py${PYTHON_SUFFIX}-dbus>=0.84.0:${PORTSDIR}/devel/py-dbus \
		py${PYTHON_SUFFIX}-notify>=0.1.1_9:${PORTSDIR}/devel/py-notify \
		py${PYTHON_SUFFIX}-vte>=0.26.2_1:${PORTSDIR}/x11-toolkits/py-vte \
		py${PYTHON_SUFFIX}-xdg>=0.19:${PORTSDIR}/devel/py-xdg
RUN_DEPENDS=	py${PYTHON_SUFFIX}-dbus>=0.84.0:${PORTSDIR}/devel/py-dbus \
		py${PYTHON_SUFFIX}-notify>=0.1.1_9:${PORTSDIR}/devel/py-notify \
		py${PYTHON_SUFFIX}-vte>=0.26.2_1:${PORTSDIR}/x11-toolkits/py-vte \
		py${PYTHON_SUFFIX}-xdg>=0.19:${PORTSDIR}/devel/py-xdg

#GH_ACCOUNT=	Guake
#GH_TAGNAME=	${PORTVERSION:R}
#GH_COMMIT=	88af26c
GCONF_SCHEMAS=	guake.schemas
GNU_CONFIGURE=	yes

INSTALLS_ICONS=	yes

NLS_CONFIGURE_ON=	--localedir=${PREFIX}/share/locale
NLS_CONFIGURE_OFF=	--disable-nls

OPTIONS_DEFINE=	MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	MANPAGES NLS

PLIST_SUB+=	DESKTOPDIR="${DESKTOPDIR:S,${PREFIX}/,,}"

REINPLACE_ARGS=	-e 's,/usr/bin/env python,&${PYTHON_VER},' -i.bak
REINPLACE_FILES=	guake guake-prefs prefs.py

#USE_GITHUB=	yes
USE_GNOME=	gtk20 pygnome2
USE_PYTHON=	-2.7
USES=	desktop-file-utils gmake pkgconfig

WRKSRC=	${WRKDIR}/${DISTNAME}

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MMANPAGES}
MAKE_ENV+=	man_MANS=""
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
.else
REINPLACE_ARGS=	-E -e 's,(USE_NLS=)yes,\1no,'
REINPLACE_FILES=	../configure
.endif

post-patch:
	@cd ${WRKSRC}/src && ${REINPLACE_CMD} ${REINPLACE_FILES}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/libexec/notification-daemon)
RUN_DEPENDS+=	notification-daemon>=0.7.2_1:${PORTSDIR}/deskutils/notification-daemon
.elif exists (${LOCALBASE}/bin/xfce4-notifyd-config)
RUN_DEPENDS+=	xfce4-notifyd>=0.2.4:${PORTSDIR}/deskutils/xfce4-notifyd
.else
RUN_DEPENDS+=	notify-osd>=0.9.29_4:${PORTSDIR}/deskutils/notify-osd
.endif

.include <bsd.port.post.mk>
