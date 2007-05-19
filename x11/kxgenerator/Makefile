# New ports collection makefile for:	kxgenerator
# Date created:		2006-12-10
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kxgenerator
PORTVERSION=	0.3.7
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	http://dp0154.debowypark.waw.pl/kxgenerator/data/download/

MAINTAINER=	makc@issp.ac.ru
COMMENT=	KDE utility to configure the X server

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes

pre-configure:
.for i in properties.h main.cpp
	@${REINPLACE_CMD} -e "s:/usr/lib/xorg:${X11BASE}/lib:g"	\
		${WRKSRC}/src/${i}
.endfor

.include <bsd.port.mk>
