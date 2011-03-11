# New ports collection makefile for:	olvwm
# Date created:		21 October 1994
# Whom:			smace
#
# $FreeBSD$
#

PORTNAME=	olvwm
PORTVERSION=	4.2
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	window_managers
DISTNAME=	${PORTNAME}4
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	olvwm4.Patch01.Z \
		olvwm4.Patch02.Z
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenLook Virtual Window manager

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

REINPLACE_ARGS= -i ""
NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
USE_XORG=	xpm
MAN1=		olvwm.1 olvwmrc.1
XFREE86_HTML_MAN=	no

pre-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
	's|^#endif.*$$|#endif|;s|^#else.*$$|#else|;\
	s|^/\*\*/#*|XCOMM |'

.include <bsd.port.mk>
