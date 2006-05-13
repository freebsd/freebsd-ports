# New ports collection makefile for:	uwm
# Date created:				2000-10-16
# Whom:					trevor
#
# based on the NetBSD package
# $NetBSD: Makefile,v 1.2 2000/02/02 08:07:07 itohy Exp $
# $FreeBSD$
#

PORTNAME=	uwm
PORTVERSION=	19881027
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_NETBSD}
DISTNAME=	X.V11R3uwm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11R3 window manager

MAN1=		uwm.1
PLIST=		${WRKDIR}/pkg-plist
USE_IMAKE=	yes
REINPLACE_ARGS=	-i'' -E
WRKSRC=		${WRKDIR}/X.V11R3/clients/uwm

post-patch:
	${REINPLACE_CMD} 's:/usr/lib/X11:${PREFIX}/lib/X11:g' ${WRKSRC}/uwm.man

pre-install:
	${ECHO_CMD} bin/uwm > ${PLIST}
	${ECHO_CMD} lib/X11/uwm/system.uwmrc >> ${PLIST}
	${ECHO_CMD} @dirrm lib/X11/uwm >> ${PLIST}

post-install:
	${MKDIR} ${PREFIX}/lib/X11/uwm
	${INSTALL_DATA} ${WRKSRC}/default.uwmrc \
		${PREFIX}/lib/X11/uwm/system.uwmrc

.include <bsd.port.mk>
