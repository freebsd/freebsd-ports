# New ports collection makefile for:	qnxstyle
# Date created:				Sun May 12 00:55:29 CEST 2002
# Whom:				Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	qnxstyle
PORTVERSION=	0.1
CATEGORIES=	x11-wm kde
MASTER_SITES=	http://www.kde-look.org/content/files/
DISTNAME=	$(KDELOOKITEM)-${PORTNAME}-$(PORTVERSION)

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A QNX style/theme for KDE3

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14

.include <bsd.port.pre.mk>

KDELOOKITEM=	1444

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.post.mk>
