# -*-mode: makefile-*-
# New ports collection makefile for:	KDE3
# Date created:				Sun May 14 2000 00:50:02
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	kde
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER?=	kde@FreeBSD.org
COMMENT?=	The "meta-port" for KDE

# This port conflicts with the kde-lite port, so make it known.
.if defined(IS_INTERACTIVE)
CONFLICTS?=	kde-lite-[0-9]*
.endif

## This is the file where the selections made in the interactive dialog
## are saved in and initialized from.

.if defined(KDE_PREFIX)
CONFIG_FILE=	${KDE_PREFIX}/etc/kde-meta.conf
.else
CONFIG_FILE=	${LOCALBASE}/etc/kde-meta.conf
.endif

## The list of all modules that make up KDE, excluding the base modules
## arts, kdebase and kdelibs

ALL_MODULES=	KDEADDONS KDEADMIN KDEARTWORK KDEVELOP KDEEDU KDEGAMES \
		KDEGRAPHICS KDEMULTIMEDIA KDENETWORK KOFFICE KDEPIM KDESDK \
		KDETOYS KDEUTILS QUANTA

## Forwards parts of the environment to scripts/configure.kde3

SCRIPTS_ENV+=	ALL_MODULES="${ALL_MODULES}" \
		BATCH="${BATCH}" \
		CAT="${CAT}" \
		CONFIG_FILE="${CONFIG_FILE}" \
		CURDIR="${CURDIR}" \
		ECHO="${ECHO}" \
		ECHO_MSG="${ECHO_MSG}" \
		GREP="${GREP}" \
		MKDIR="${MKDIR}" \
		PKG_DELETE="${PKG_DELETE}" \
		PKG_INFO="${PKG_INFO}" \
		REINPLACE_CMD="${REINPLACE_CMD}" \
		SED="${SED}" \
		TOUCH="${TOUCH}" \
		TR="${TR}" \
		WRKDIRPREFIX="${WRKDIRPREFIX}"

## If MINIMAL_KDE is defined, define WITHOUT_FOO for every
## module there is.

.if defined(MINIMAL_KDE)
.for module in ${ALL_MODULES}
WITHOUT_${module}=yes
.endfor
.endif

## If the user has some WITHOUT_FOO stuff set that matters to us,
## define BATCH so interactive configuration will be skipped.

.for module in ${ALL_MODULES}
.if defined(WITHOUT_${module})
BATCH=		yes
.endif
.endfor

## If the user (or the packagecluster) defines batchprocessing, skip
## the interactive configuration. Otherwise declare this port properly
## as interactive, launch the selector script cand include the configuration
## file that's being returned by it (Makefile.inc). Remove the file on make
## clean.

.if !defined(BATCH) && !defined(PACKAGE_BUILDING) && !defined(MINIMAL_KDE)
IS_INTERACTIVE=	yes
PLIST_SUB+=	IS_INTERACTIVE=""
.else
PLIST_SUB+=	IS_INTERACTIVE="@comment "
.endif

.if !defined(BATCH)
pre-fetch:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.kde3

post-configure:
	@/usr/bin/clear
	@${CAT} ${FILESDIR}/post-configure-message

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.endif # !defined(BATCH)

## Allow to turn off every optional bit of KDE.

.if !defined(WITHOUT_KDEGAMES)
RUN_DEPENDS+=	kjumpingcube:${PORTSDIR}/games/kdegames3
.endif
.if !defined(WITHOUT_KDEUTILS)
RUN_DEPENDS+=	kdessh:${PORTSDIR}/misc/kdeutils3
.endif
.if !defined(WITHOUT_KOFFICE)
RUN_DEPENDS+=	kword:${PORTSDIR}/editors/koffice-kde3
.endif
.if !defined(WITHOUT_KDENETWORK)
RUN_DEPENDS+=	kppp:${PORTSDIR}/net/kdenetwork3
.endif
.if !defined(WITHOUT_KDEGRAPHICS)
RUN_DEPENDS+=	kview:${PORTSDIR}/graphics/kdegraphics3
.endif
.if !defined(WITHOUT_KDEMULTIMEDIA)
RUN_DEPENDS+=	kmix:${PORTSDIR}/multimedia/kdemultimedia3
.endif
.if !defined(WITHOUT_KDEPIM)
RUN_DEPENDS+=	korganizer:${PORTSDIR}/deskutils/kdepim3
.endif
.if !defined(WITHOUT_KDESDK)
RUN_DEPENDS+=	cervisia:${PORTSDIR}/devel/kdesdk3
.endif
.if !defined(WITHOUT_KDEVELOP)
RUN_DEPENDS+=	kdevelop:${PORTSDIR}/devel/kdevelop
.endif
.if !defined(WITHOUT_KDEADDONS)
RUN_DEPENDS+=	atlantikdesigner:${PORTSDIR}/misc/kdeaddons3
.endif
.if !defined(WITHOUT_KDEEDU)
RUN_DEPENDS+=	khangman:${PORTSDIR}/misc/kdeedu3
.endif
.if !defined(WITHOUT_KDEADMIN)
RUN_DEPENDS+=	kcron:${PORTSDIR}/sysutils/kdeadmin3
.endif
.if !defined(WITHOUT_QUANTA)
RUN_DEPENDS+=	quanta:${PORTSDIR}/www/quanta
.endif
.if !defined(WITHOUT_KDETOYS)
RUN_DEPENDS+=	kmoon:${PORTSDIR}/x11-clocks/kdetoys3
.endif
.if !defined(WITHOUT_KDEARTWORK)
RUN_DEPENDS+=	kmatrix.kss:${PORTSDIR}/x11-wm/kdeartwork3
.endif

.if make(package)
DEPENDS_TARGET="package"
.endif # .if make(package)

USE_KDELIBS_VER=3
USE_KDEBASE_VER=3

NO_BUILD=	yes

## Copy Makefile.inc to ${OPTION_FILE} where it will serve as memory of the
## user's last selection.

do-install:
.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
	@${INSTALL_DATA} ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc ${CONFIG_FILE}
.endif

.include <bsd.port.mk>
