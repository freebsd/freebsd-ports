# New ports collection makefile for:	fluxbox
# Date created:				29 November 2001
# Whom:					spn
#
# $FreeBSD$
#

PORTNAME=	fluxbox
PORTVERSION=	0.1.13
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=	http://www.cse.unsw.edu.au/~simonb/
PATCH_DIST_STRIP=	-p1
PATCHFILES=	fluxbox.openoffice.patch fluxbox-0.1.13.aa2.patch
.if defined(WITH_REMEMBER)
PATCHFILES+=	fluxbox-remember-patch-0.1.13.gz
.endif

MAINTAINER=	hendrik@scholz.net

RUN_DEPENDS=	bsetbg:${PORTSDIR}/x11-wm/boxtools \
		xterm:${PORTSDIR}/x11/XFree86-4-clients
BUILD_DEPENDS=	xterm:${PORTSDIR}/x11/XFree86-4-clients
.if defined(WITH_REMEMBER)
BUILD_DEPENDS+=	automake14:${PORTSDIR}/devel/automake14
.endif

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOMENG=	yes
WANT_GNOME=	yes
.if defined(WITH_REMEMBER)
USE_GMAKE=	yes
CONFIGURE_ENV=	AUTOMAKE="${AUTOMAKE}"
.endif
CONFIGURE_ARGS=	--disable-newwmspec
.if defined(WITH_KDE) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-kde
.endif
.if defined(WITH_XINERAMA) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-xinerama
.endif

MAN1=		fluxbox.1

.include <bsd.port.pre.mk>

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
	@${ECHO_CMD} ""

.include <bsd.port.post.mk>
