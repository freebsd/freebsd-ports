# $FreeBSD$

PORTNAME=	guake
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Dropdown terminal made for the GNOME desktop

LICENSE=	GPLv2

BUILD_DEPENDS=	gnome-common>=3.14.0:${PORTSDIR}/devel/gnome-common \
		py${PYTHON_SUFFIX}-dbus>=0.84.0:${PORTSDIR}/devel/py-dbus \
		py${PYTHON_SUFFIX}-notify>=0.1.1_9:${PORTSDIR}/devel/py-notify \
		py${PYTHON_SUFFIX}-vte>=0.26.2_1:${PORTSDIR}/x11-toolkits/py-vte \
		py${PYTHON_SUFFIX}-xdg>=0.19:${PORTSDIR}/devel/py-xdg
RUN_DEPENDS=	py${PYTHON_SUFFIX}-dbus>=0.84.0:${PORTSDIR}/devel/py-dbus \
		py${PYTHON_SUFFIX}-notify>=0.1.1_9:${PORTSDIR}/devel/py-notify \
		py${PYTHON_SUFFIX}-vte>=0.26.2_1:${PORTSDIR}/x11-toolkits/py-vte \
		py${PYTHON_SUFFIX}-xdg>=0.19:${PORTSDIR}/devel/py-xdg

CPPFLAGS+=	-I${LOCALBASE}/include

GCONF_SCHEMAS=	guake.schemas
GH_ACCOUNT=	Guake
GH_COMMIT=	aaa3e45
GH_TAGNAME=	${PORTVERSION}
GNU_CONFIGURE=	yes

INSTALLS_ICONS=	yes

LIBS+=		-L${LOCALBASE}/lib

MANPAGES_MAKE_ENV_OFF=	man_MANS=""

NLS_CONFIGURE_ENABLE=	nls

OPTIONS_DEFINE=	MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	NLS

PLIST_SUB+=	DESKTOPDIR="${DESKTOPDIR:S,${PREFIX}/,,}"

USES=		autoreconf:build desktop-file-utils gettext gmake libtool \
		pkgconfig python:2
USE_GITHUB=	yes
USE_GNOME=	gtk20 pygnome2

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MNLS}
REINPLACE_ARGS+=	-e 's,\(USE_NLS=\)yes,\1no,'
REINPLACE_FILES+=	../../configure
.endif

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} ; ${SETENV} ${CONFIGURE_ENV} ./autogen.sh)

post-build:
	@${STRIP_CMD} ${WRKSRC}/src/guake/globalhotkeys/.libs/globalhotkeys.so

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/libexec/notification-daemon)
RUN_DEPENDS+=	notification-daemon>=0.7.2_1:${PORTSDIR}/deskutils/notification-daemon
.elif exists (${LOCALBASE}/bin/xfce4-notifyd-config)
RUN_DEPENDS+=	xfce4-notifyd>=0.2.4:${PORTSDIR}/deskutils/xfce4-notifyd
.else
RUN_DEPENDS+=	notify-osd>=0.9.29_4:${PORTSDIR}/deskutils/notify-osd
.endif

.include <bsd.port.post.mk>
