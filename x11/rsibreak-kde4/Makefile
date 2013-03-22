# New ports collection makefile for:	RSIBreak
# Date created:			15 Mar 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rsibreak
DISTVERSION=	0.11-beta1
PORTREVISION=	2
CATEGORIES=	x11 kde
MASTER_SITES=	http://www.rsibreak.org/files/

MAINTAINER=	avg@icyb.net.ua
COMMENT=	A KDE RSI prevention tool

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_GETTEXT=	yes
USES=		cmake
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_KDE4=	kdehier kdeprefix kdelibs automoc4
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
