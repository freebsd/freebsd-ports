# New ports collection makefile for:	login.app
# Date created:				17 January 1999
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	login.app
PORTVERSION= 	2.0.0.a7
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://wm.current.nu/files/Login.app/
DISTNAME=	Login.app-${PORTVERSION:S/.a/-Alpha-/}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	wraster.3:${PORTSDIR}/x11-wm/windowmaker \
		PropList.2:${PORTSDIR}/devel/libPropList

USE_X_PREFIX=	yes
USE_XPM=	yes
MAKE_ENV=	MKDIR="${MKDIR}"

ALL_TARGET=	Login

post-configure:
	@cd ${WRKSRC} && ${PERL} -pi -e 's|%%X11BASE%%|${X11BASE}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' preferences.h Scripts/Login.user \
		Scripts/Login.root Scripts/Logout.root Scripts/Startup \
		Preferences config.h

.include <bsd.port.mk>
