# New ports collection makefile for:	KDE3
# Date created:				Sun May 14 2000 00:50:02
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	kde@FreeBSD.org

RUN_DEPENDS+=	kjumpingcube:${PORTSDIR}/games/kdegames3 \
		kdessh:${PORTSDIR}/misc/kdeutils3 \
		kword:${PORTSDIR}/editors/koffice-kde3 \
		kppp:${PORTSDIR}/net/kdenetwork3 \
		kview:${PORTSDIR}/graphics/kdegraphics3 \
		kmidi:${PORTSDIR}/audio/kdemultimedia3

.if make(package)
DEPENDS_TARGET="package"
.endif

USE_QT_VER=3
USE_KDELIBS_VER=3
USE_KDEBASE_VER=3

NO_BUILD=	yes

.if !defined(NO_QT_WARNING)
SLEEP?=/bin/sleep
pre-everything::
	@if test -e ${LOCALBASE}/bin/dcop; then \
	    ${ECHO_MSG};\
	    ${ECHO_MSG} \
	    "============================================================";\
	    ${ECHO_MSG} "===> " \
	    "WARNING!!!";\
	    ${ECHO_MSG} "===> " \
	    "If you are upgrading Qt from 3.0.4 or an earlier 3.0.x";\
	    ${ECHO_MSG} "===> " \
	    "version, or have just done so, you MUST remove kdelibs";\
	    ${ECHO_MSG} "===> " \
	    "using 'pkg_delete -f kdelibs' before making this port.";\
	    ${ECHO_MSG} \
	    "============================================================";\
	    ${ECHO_MSG}; ${SLEEP} 10;\
	else \
	    ${TRUE};\
	fi
.endif

do-install:	# empty
	${DO_NADA}

.include <bsd.port.mk>
