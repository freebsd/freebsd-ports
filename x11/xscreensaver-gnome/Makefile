# New ports collection makefile for:	xscreensaver-gnome
# Date created:				13th February 2002
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

MAINDIR=	${.CURDIR}/../xscreensaver

PORTNAME=	xscreensaver-gnome
PORTVERSION!=	${MAKE} -V PORTVERSION -f ${MAINDIR}/${MAKEFILE}
PORTREVISION!=	${MAKE} -V PORTREVISION -f ${MAINDIR}/${MAKEFILE}
PORTEPOCH!=	${MAKE} -V PORTEPOCH -f ${MAINDIR}/${MAKEFILE}
CATEGORIES=	x11 gnome
DISTFILES=

MAINTAINER=	gnome@FreeBSD.org

FETCH_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/x11/xscreensaver:patch
BUILD_DEPENDS!=	${MAKE} -V BUILD_DEPENDS -f ${MAINDIR}/${MAKEFILE}
LIB_DEPENDS!=	${MAKE} -V LIB_DEPENDS -f ${MAINDIR}/${MAKEFILE}
RUN_DEPENDS!=	${MAKE} -V RUN_DEPENDS -f ${MAINDIR}/${MAKEFILE}

RUN_DEPENDS+=	xscreensaver:${PORTSDIR}/x11/xscreensaver

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehier gnomelibs libcapplet gdkpixbuf
GNU_CONFIGURE=	yes
OLD_CONFIGURE_ARGS!=	${MAKE} -V CONFIGURE_ARGS -f ${MAINDIR}/${MAKEFILE}
CONFIGURE_ARGS=	${OLD_CONFIGURE_ARGS:N--without-gnome} --with-gnome
CONFIGURE_ENV!=	${MAKE} -V CONFIGURE_ENV -f ${MAINDIR}/${MAKEFILE}

post-extract:
	@${CP} -Rp ${WRKDIRPREFIX}${MAINDIR}/work/xscreensaver-${PORTVERSION} \
		${WRKSRC}
	@${RM} -f ${WRKSRC}/config.cache

do-build:
	@cd ${WRKSRC}/driver && ${GMAKE} clean xscreensaver-demo \
		screensaver-properties.desktop

do-install:
	@${INSTALL_DATA} ${WRKSRC}/utils/images/screensaver-*.xpm \
		${PREFIX}/share/gnome/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/utils/images/logo-50.xpm \
		${PREFIX}/share/gnome/pixmaps/xscreensaver.xpm
	@${INSTALL_PROGRAM} ${WRKSRC}/driver/xscreensaver-demo \
		${PREFIX}/bin/xscreensaver-gnome
	@${INSTALL_SCRIPT} ${WRKSRC}/driver/screensaver-properties-capplet \
		${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/driver/screensaver-properties.desktop \
		${PREFIX}/share/gnome/apps/Settings/Desktop
	@${INSTALL_DATA} ${WRKSRC}/driver/screensaver-properties.desktop \
		${PREFIX}/share/gnome/control-center/Desktop

.include <bsd.port.mk>
