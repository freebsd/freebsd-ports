# New ports collection makefile for:	login.app
# Date created:				17 January 1999
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	login.app
PORTVERSION=	2.0.0.a7
PORTREVISION=	1
CATEGORIES=	x11 windowmaker
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://wm.current.nu/files/Login.app/ \
		http://wm.current.nu/files/Login.app/Themes/
MASTER_SITE_SUBDIR=	sobomax
DISTFILES=	Login.app-${PORTVERSION:S/.a/-Alpha-/}${EXTRACT_SUFX} \
		Drone${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice looking login interface to your favorite X-Server

LIB_DEPENDS=	wraster.4:${PORTSDIR}/x11-wm/windowmaker \
		PropList.2:${PORTSDIR}/devel/libPropList

WRKSRC=		${WRKDIR}/Login.app-${PORTVERSION:S/.a/-Alpha-/}

USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes
USE_XPM=	yes
MAKE_ENV=	MKDIR="${MKDIR}"

ALL_TARGET=	Login

post-configure:
	@cd ${WRKSRC} && ${PERL} -pi -e 's|%%X11BASE%%|${X11BASE}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' preferences.h Scripts/Login.user \
		Scripts/Login.root Scripts/Logout.root Scripts/Startup \
		Preferences config.h

post-install:
	@(cd ${WRKDIR} && ${TAR} --exclude "*.orig" -c -f - Drone) \
		| (cd ${PREFIX}/GNUstep/Apps/Login.app/Themes && ${TAR} --unlink -x -f -)

.include <bsd.port.mk>
