# New ports collection Makefile for:    oooqs2
# Date created:                 16 Mar 2007
# Whom:                         Rashid N. Achilov <citycat4@ngs.ru>
#
# $FreeBSD$

PORTNAME=		oooqs2
PORTVERSION=		1.0
PORTREVISION=	4
CATEGORIES=		x11
MASTER_SITES=		http://download.berlios.de/segfaultskde/ \
			http://download2.berlios.de/segfaultskde/ \

MAINTAINER=		citycat4@ngs.ru
COMMENT=		KDE Quick launcher for Open Office 2.x

USE_AUTOTOOLS=		libtool:22

CONFIGURE_ARGS+=	--with-qt-dir=${QT_PREFIX}

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
INSTALLS_ICONS=		1

DOCSDIR=		${PREFIX}/share/doc/HTML

.include <bsd.port.mk>
