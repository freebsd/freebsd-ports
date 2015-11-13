# Created by: Sergey Matveychuk <sem@ciam.ru>
# $FreeBSD$

PORTNAME=	ede
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	SF \
		SF/${PORTNAME}/${PORTNAME}lib/${PORTVERSION}:edelib
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${EDELIB_DISTFILE}:edelib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Equinox Desktop Environment

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen \
		jam:${PORTSDIR}/devel/jam
LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libfltk.so:${PORTSDIR}/x11-toolkits/fltk

USES=		fam gettext iconv:translit pathfix pkgconfig python:2 \
		shared-mime-info shebangfix
SHEBANG_FILES=	doc/asciidoc/asciidoc.py
USE_XORG=	xcomposite xft xinerama xkbfile xpm xrandr
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PEKWM_CXXFLAGS="${CXXFLAGS}" \
		PKG_CONFIG_PATH="${EDELIB_WRKSRC}/pc"
CONFIGURE_ARGS=	--with-edelib-path=${EDELIB_WRKSRC} \
		--with-fltk-path=${LOCALBASE}
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS_INSTALL=	pekwm-[0-9]*

OPTIONS_DEFINE=		HAL

HAL_LIB_DEPENDS=	libhal.so.1:${PORTSDIR}/sysutils/hal
HAL_CONFIGURE_ENABLE=	hal

EDELIB_NAME=	edelib
EDELIB_VERSION=	${PORTVERSION}
EDELIB_DISTNAME=${EDELIB_NAME}-${EDELIB_VERSION}
EDELIB_DISTFILE=${EDELIB_DISTNAME}${EXTRACT_SUFX}
EDELIB_WRKSRC=	${WRKDIR}/${EDELIB_DISTNAME}

post-extract:
	@${LN} -sf ${EDELIB_WRKSRC} ${WRKDIR}/${EDELIB_NAME}

post-patch:
	@${REINPLACE_CMD} -e \
		'/DEVELOPER_FLAGS=/s|-pedantic|| ; \
		 /OPTIM_FLAGS=/s|-O2|-fPIC| ; \
		 s|_daylight=yes|_daylight=no| ; \
		 s|/usr/local/share|${LOCALBASE}/share|' \
		${EDELIB_WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|$$(CC)|@CXX@| ; \
		 /-lstdc++/s|^|#|' ${EDELIB_WRKSRC}/Jamconfig.in
	@${REINPLACE_CMD} -e \
		's| -liconv| ${ICONV_LIB}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|$$(CC)|@CXX@| ; \
		 /panel-applets/s|EDE_DATA_DIR|libdir| ; \
		 /-lstdc++/s|^|#|' ${WRKSRC}/Jamconfig.in
	@${REINPLACE_CMD} -e \
		'/desktop-links/s|^|#|' ${WRKSRC}/data/Jamfile
	@${REINPLACE_CMD} -e \
		'/-ldl/s|^|#|' ${WRKSRC}/ede-panel/Jamfile
	@${REINPLACE_CMD} -e \
		's|"\(panel-applets\)"|"../../lib/ede/\1"|' \
		${WRKSRC}/ede-panel/Panel.cpp

pre-configure:
	@(cd ${EDELIB_WRKSRC} \
		&& ${SETENV} ${CONFIGURE_ENV} ./configure \
		--prefix=${WRKDIR}/fakeroot \
		--with-fltk-path=${LOCALBASE} \
		--build=${CONFIGURE_TARGET} \
		CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}")

post-configure:
	@${REINPLACE_CMD} -e \
		's|#define ICONV_CONST 1|#undef ICONV_CONST|' ${WRKSRC}/config.h

pre-build:
	@(cd ${EDELIB_WRKSRC} \
		&& ${LOCALBASE}/bin/jam -j${MAKE_JOBS_NUMBER} \
		&& ${LOCALBASE}/bin/jam ${INSTALL_TARGET})

do-build:
	@(cd ${BUILD_WRKSRC} && ${LOCALBASE}/bin/jam -j${MAKE_JOBS_NUMBER})

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} DESTDIR="${STAGEDIR}" \
		${LOCALBASE}/bin/jam ${INSTALL_TARGET})
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ede-2.1.0/manual/images
	@(cd ${WRKSRC}/doc/manual/images && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/doc/ede-2.1.0/manual/images)
.for i in ede-about ede-autostart ede-bell-conf ede-bug-report ede-crasher \
	ede-calc ede-conf ede-desktop ede-desktop-conf ede-dialog \
	ede-keyboard-conf ede-notify-daemon ede-screensaver-conf \
	ede-image-view ede-launch ede-timedate ede-tip ede-tip-compiler \
	ede-preferred-applications evoke ede-shutdown ede-panel pekwm
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor
.for i in battery_monitor.so clock.so cpu_monitor.so keyboard_layout.so \
	mem_monitor.so pager.so quick_launch.so start_menu.so \
	system_tray.so taskbar.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ede/panel-applets/${i}
.endfor

.include <bsd.port.mk>
