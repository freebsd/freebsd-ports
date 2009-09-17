# New ports collection makefile for:	xscreensaver-kde
# Date created:				July 08 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xscreensaver-kde
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	4
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
PKGNAMEPREFIX=	kdeartwork-
DISTNAME=	kdeartwork-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Support for xscreensaver blankers in KDE

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kdeartwork-${PORTVERSION}

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/share/applications/xscreensaver-properties.desktop)
WITH_XSGNOME=	yes
.elif exists(${LOCALBASE}/bin/screensaver)
WITH_XSGNOME=	yes
.else
WITH_XS=	yes
.endif

.if defined(WITH_XS) && !defined(WITH_XSGNOME)
BUILD_DEPENDS+=	xscreensaver:${PORTSDIR}/x11/xscreensaver
RUN_DEPENDS+=	xscreensaver:${PORTSDIR}/x11/xscreensaver
.endif # defined(WITH_XS)

.if defined(WITH_XSGNOME)
BUILD_DEPENDS+=	${LOCALBASE}/share/applications/xscreensaver-properties.desktop:${PORTSDIR}/x11/xscreensaver-gnome
RUN_DEPENDS+=	${LOCALBASE}/share/applications/xscreensaver-properties.desktop:${PORTSDIR}/x11/xscreensaver-gnome
.endif # defined(WITH_XSGNOME)

pre-configure:
	@${ECHO_CMD} "kscreensaver" > ${WRKSRC}/inst-apps
	@${REINPLACE_CMD} -e 's|kdesavers||g' -e 's|kpartsaver||g' -e 's|xsavers||g' \
		${WRKSRC}/kscreensaver/Makefile.in

.include <bsd.port.post.mk>
