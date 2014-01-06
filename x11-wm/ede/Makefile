# Created by: Sergey Matveychuk <sem@ciam.ru>
# $FreeBSD$

PORTNAME=	ede
PORTVERSION=	2.0
PORTREVISION=	3
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
		jam:${PORTSDIR}/devel/jam \
		python:${PORTSDIR}/lang/python
LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libfltk.so:${PORTSDIR}/x11-toolkits/fltk

OPTIONS_DEFINE=	HAL
HAL_DESC=	Enable HAL support

USES=		fam iconv gettext pathfix pkgconfig shared-mime-info
USE_XORG=	xcomposite xft xinerama xpm xrandr
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-edelib_path=${EDELIB_WRKSRC} \
		--with-fltk-path=${LOCALBASE}
INSTALL_ICONS=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS_INSTALL=	pekwm-[0-9]*

EDELIB_NAME=	edelib
EDELIB_VERSION=	${PORTVERSION}
EDELIB_DISTNAME=${EDELIB_NAME}-${EDELIB_VERSION}
EDELIB_DISTFILE=${EDELIB_DISTNAME}${EXTRACT_SUFX}
EDELIB_WRKSRC=	${WRKDIR}/${EDELIB_DISTNAME}

HAL_LIB_DEPENDS=	libhal.so.1:${PORTSDIR}/sysutils/hal
HAL_CONFIGURE_OFF=	--disable-hal

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/share|${LOCALBASE}/share| ; \
		 /OPTIM_FLAGS=/s|-O2|-fPIC| ; \
		 s|_daylight=yes|_daylight=no|' ${EDELIB_WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's| -liconv| ${ICONV_LIB}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|$$(CC)|@CXX@| ; \
		 s|-lstdc++||' ${WRKSRC}/Jamconfig.in

pre-configure:
	@(cd ${EDELIB_WRKSRC} \
		&& ${SETENV} ${CONFIGURE_ENV} ./configure \
		--prefix=${WRKDIR}/fakeroot \
		--with-fltk-path=${LOCALBASE} \
		--build=${CONFIGURE_TARGET} \
		CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}")

pre-build:
	@(cd ${EDELIB_WRKSRC} \
		&& ${LOCALBASE}/bin/jam -j${MAKE_JOBS_NUMBER} \
		&& ${LOCALBASE}/bin/jam ${INSTALL_TARGET})

do-build:
	@(cd ${BUILD_WRKSRC} && ${LOCALBASE}/bin/jam -j${MAKE_JOBS_NUMBER})

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} DESTDIR="${STAGEDIR}" \
		${LOCALBASE}/bin/jam ${INSTALL_TARGET})
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ede-2.0.0/manual/images
	@(cd ${WRKSRC}/doc/manual/images && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/doc/ede-2.0.0/manual/images)
.for i in ede-about ede-autostart ede-bell-conf ede-bug-report ede-crasher \
	ede-calc ede-conf ede-desktop ede-desktop-conf ede-dialog \
	ede-keyboard-conf ede-notify-daemon ede-screensaver-conf \
	ede-image-view ede-launch emountd ede-timedate ede-tip \
	ede-tip-compiler ede-preferred-applications evoke ede-shutdown \
	ede-panel ede-menu-spec-test pekwm
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor

.include <bsd.port.mk>
