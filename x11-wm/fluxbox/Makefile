# New ports collection makefile for:	fluxbox
# Date created:				29 November 2001
# Whom:					spn
#
# $FreeBSD$
#

PORTNAME=	fluxbox
PORTVERSION=	0.1.14
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

.if defined(WITH_REMEMBER)
PATCH_SITES=	http://www.bugfactory.org/~gav/fluxbox/
PATCH_DIST_STRIP=	-p1
PATCHFILES=	remember-0.1.14-7.gz
.endif

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A small and fast window manager based on BlackBox

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft
RUN_DEPENDS=	bsetbg:${PORTSDIR}/x11-wm/boxtools
.if defined(WITH_REMEMBER)
WANT_AUTOMAKE_VER=14
.endif

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
.if defined(WITH_REMEMBER)
USE_GMAKE=	yes
CONFIGURE_ENV=	AUTOMAKE=automake14
.endif
CONFIGURE_ARGS=	--disable-newwmspec
.if defined(WITH_KDE) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-kde
.endif
.if defined(WITH_XINERAMA) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-xinerama
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
.undef WITH_WINSNAP
.endif

.if defined(WITH_WINSNAP)
PATCH_SITES+=	http://www.raisdorf.net/files/FreeBSD/
PATCH_DIST_STRIP=	-p1
PATCHFILES+=	winsnap-0.1.14.patch
.endif

MAN1=		fluxbox.1

.if ${HAVE_GNOME:Mgnomelibs}!="" || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-gnome
.endif

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Definable build options"
	@${ECHO_CMD} "-----------------------"
.if !defined(WITH_XINERAMA)
	@${ECHO_CMD} "WITH_XINERAMA	- Enable Xinerama support"
.endif
.if !defined(WITH_KDE)
	@${ECHO_CMD} "WITH_KDE	- Enable KDE slit support"
.endif
.if !defined(WITH_REMEMBER)
	@${ECHO_CMD} "WITH_REMEMBER	- Enable the unofficial remember patch"
.endif
.if !defined(WITH_WINSNAP)
	@${ECHO_CMD} "WITH_WINSNAP	- Enable the unofficial window snapping patch"
	@${ECHO_CMD} "            	  (does not work on -current)"
.endif
	@${ECHO_CMD} ""

post-install:
.if defined(WITH_WINSNAP)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "The window snapping patch from Shawn Singh requires some"
	@${ECHO_CMD} "changes to your ~/.fluxbox/init file:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "    session.screen0.edgeSnapThreshold: 10"
	@${ECHO_CMD} "    session.screen0.edgeResistThreshold: 10"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "The values can be changed to mimic the behavior of Enlightenment:"
	@${ECHO_CMD} "snap: 3, resist: 15"
	@${ECHO_CMD} ""
.endif

.include <bsd.port.post.mk>
