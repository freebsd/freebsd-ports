# New ports collection makefile for:	keramik
# Date created:		June 22 2002
# Whom:			Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	keramik
PORTVERSION=	1.0
CATEGORIES=	x11-wm kde
MASTER_SITES=	http://www.kde-look.org/content/files/
DISTNAME=	2194-${PORTNAME}

MAINTAINER=	adam@vectors.cx

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake \
		autoconf:${PORTSDIR}/devel/autoconf

.if !defined(REALLY_OVERWRITE_KDE_WITH_KERAMIK)
BROKEN=		"Overwrites KDE base install"
.endif

WRKSRC= 	${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDEBASE_VER=3
INSTALLS_SHLIB=	yes

pre-configure:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} -f Makefile.cvs
	${TOUCH} ${WRKSRC}/startkde

.include <bsd.port.mk>
