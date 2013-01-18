# $FreeBSD$

PORTNAME=	guake
PORTVERSION=	0.4.4.0
#PORTREVISION=	0
CATEGORIES=	x11
MASTER_SITES=	http://www.guake.org/downloads/5?dummy=empty/

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

GCONF_SCHEMAS=	guake.schemas
GNU_CONFIGURE=	yes

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES NLS
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANPAGES}
MAN1=	guake.1
.else
MAKE_ENV=	man_MANS=""
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS=	--localedir=${PREFIX}/share/locale
PLIST_SUB=	NLS=""
USE_GETTEXT=	yes
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB=	NLS="@comment "
REINPLACE_ARGS=	-E -e 's,(USE_NLS=)yes,\1no,'
REINPLACE_FILES=	../configure
.endif

PLIST_SUB+=	DESKTOPDIR="${DESKTOPDIR:S,${PREFIX}/,,}"

REINPLACE_ARGS+=	-e 's,/usr/bin/env python,&${PYTHON_VER},' -i.bak
REINPLACE_FILES+=	guake guake-prefs prefs.py

USE_GMAKE=	yes
USE_GNOME=	desktopfileutils gtk20 pygnome2
USE_PYTHON=	-2.7

WRKSRC=	${WRKDIR}/${DISTNAME:R}

post-patch:
	cd ${WRKSRC}/src && ${REINPLACE_CMD} ${REINPLACE_FILES}

post-install:
	-${LOCALBASE}/bin/update-desktop-database

.include <bsd.port.mk>
