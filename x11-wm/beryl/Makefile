# New ports collection makefile for:    beryl
# Date created:				Nov 27 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beryl
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	Beryl Composite/Window Manager meta-port

NO_BUILD=	yes

DEPRECATED=	No longer supported - Use compiz
EXPIRATION_DATE=	2008-08-02

BUILD_DEPENDS=	${LOCALBASE}/bin/beryl:${PORTSDIR}/x11-wm/beryl-core			\
		${LOCALBASE}/bin/beryl-manager:${PORTSDIR}/x11-wm/beryl-manager		\
		${LOCALBASE}/lib/beryl/libanimation.so:${PORTSDIR}/x11-wm/beryl-plugins	\
		${LOCALBASE}/bin/beryl-settings:${PORTSDIR}/x11-wm/beryl-settings	\
		${LOCALBASE}/bin/emerald:${PORTSDIR}/x11-wm/emerald			\
		${LOCALBASE}/share/emerald/themes/Adonis_Mod/theme.screenshot.png:${PORTSDIR}/x11-themes/emerald-themes
RUN_DEPENDS=	${BUILD_DEPENDS}

do-install:	# empty

.include <bsd.port.mk>
