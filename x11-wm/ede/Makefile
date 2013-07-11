# Created by: Sergey Matveychuk <sem@ciam.ru>
# $FreeBSD$

PORTNAME=	ede
PORTVERSION=	2.0
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
		jam:${PORTSDIR}/devel/jam \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info
LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus \
		curl:${PORTSDIR}/ftp/curl \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

OPTIONS_DEFINE=	HAL
HAL_DESC=	Enable HAL support

USE_XORG=	xcomposite xft xinerama xpm xrandr
USES=	pathfix gettext
USE_PYTHON=	yes
USE_FAM=	yes
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

# use multiple make jobs
_make_jobs=	-j${MAKE_JOBS_NUMBER}

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/share|${LOCALBASE}/share| ; \
		 /OPTIM_FLAGS=/s|-O2|-fPIC| ; \
		 s|_daylight=yes|_daylight=no|' ${EDELIB_WRKSRC}/configure

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
		&& ${LOCALBASE}/bin/jam ${_make_jobs} \
		&& ${LOCALBASE}/bin/jam ${INSTALL_TARGET})

do-build:
	@(cd ${BUILD_WRKSRC} && ${LOCALBASE}/bin/jam ${_make_jobs})

do-install:
	@(cd ${INSTALL_WRKSRC} && ${LOCALBASE}/bin/jam ${INSTALL_TARGET})
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
