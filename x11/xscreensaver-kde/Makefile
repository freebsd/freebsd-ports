# New ports collection makefile for:	xscreensaver-kde
# Date created:				July 08 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xscreensaver-kde
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
PKGNAMEPREFIX=	kdeartwork-
DISTNAME=	kdeartwork-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Support for xscreensaver blankers in KDE

CONFLICTS=	kdeartwork-3.1.* kdeartwork-3.2.[0-3]

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/kdeartwork-${PORTVERSION}

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if exists(${X11BASE}/share/gnome/control-center-2.0/capplets/screensaver-properties.desktop)
WITH_XSGNOME=	yes
.elif exists(${X11BASE}/bin/screensaver)
WITH_XSGNOME=	yes
.else
WITH_XS=	yes
.endif

.if defined(WITH_XS) && !defined(WITH_XSGNOME)
BUILD_DEPENDS+=	xscreensaver:${PORTSDIR}/x11/xscreensaver
RUN_DEPENDS+=	xscreensaver:${PORTSDIR}/x11/xscreensaver
.endif # defined(WITH_XS)

.if defined(WITH_XSGNOME)
BUILD_DEPENDS+=	${X11BASE}/share/gnome/control-center-2.0/capplets/screensaver-properties.desktop:${PORTSDIR}/x11/xscreensaver-gnome
RUN_DEPENDS+=	${X11BASE}/share/gnome/control-center-2.0/capplets/screensaver-properties.desktop:${PORTSDIR}/x11/xscreensaver-gnome
.endif # defined(WITH_XSGNOME)

pre-configure:
	@${ECHO_CMD} "kscreensaver" > ${WRKSRC}/inst-apps
	@${REINPLACE_CMD} -e 's|kdesavers||g' -e 's|kpartsaver||g' -e 's|xsavers||g' \
		${WRKSRC}/kscreensaver/Makefile.in

.include <bsd.port.post.mk>
