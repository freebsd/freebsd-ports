# New ports collection makefile for:	fluxbox
# Date created:				29 November 2001
# Whom:					spn
#
# $FreeBSD$
#

PORTNAME=	fluxbox
PORTVERSION=	0.1.12
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

.if defined(WITH_REMEMBER)
PATCH_SITES=	http://fluxbox.sourceforge.net/download/patches/
PATCHFILES=	unofficial-fluxbox-0.1.12-remember-patch.bz2
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	hendrik@scholz.net

BUILD_DEPENDS=	automake14:${PORTSDIR}/devel/automake14
RUN_DEPENDS=	bsetbg:${PORTSDIR}/x11-wm/boxtools

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOMENG=	yes
WANT_GNOME=	yes
CONFIGURE_ENV=	AUTOMAKE="${AUTOMAKE}"
.if defined(WITH_REMEMBER)
USE_GMAKE=	yes
.endif
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
.if !defined(WITH_REMEMBER)
	@${ECHO_CMD} "WITH_REMEMBER	- Enable the unofficial remember patch"
.endif
.if !defined(WITH_KDE)
	@${ECHO_CMD} "WITH_KDE	- Enable KDE slit support"
.endif
	@${ECHO_CMD} ""

.include <bsd.port.post.mk>
