# New ports collection makefile for:	libepplet
# Date created:        			18 October 1999
# Whom:					Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	libepplet
PORTVERSION=	0.5
CATEGORIES=	x11-wm devel
MASTER_SITES=	ftp://ftp.enlightenment.org/enlightenment/epplets/ \
		ftp://ftp.dti.ad.jp/pub/X/enlightenment/epplets/

DISTNAME=	epplet-base-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/Epplets-${PORTVERSION}

USE_X_PREFIX=	yes
USE_IMLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	EROOT=${X11BASE}/share/enlightenment \
		EBIN=${X11BASE}/bin
CONFIGURE_ARGS=	--enable-fsstd
INSTALLS_SHLIB=	yes

pre-patch:
	@${PERL} -pi -e 's|api epplets|api|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
