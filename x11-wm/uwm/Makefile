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
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_NETBSD}
DISTNAME=	X.V11R3uwm

MAINTAINER=	trevor@FreeBSD.org

MAN1=		uwm.1
PLIST=		${WRKDIR}/pkg-plist
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/X.V11R3/clients/uwm

post-patch:
	${PERL} -pi -e 's:/usr/lib/X11:${PREFIX}/lib/X11:g' ${WRKSRC}/uwm.man

pre-install:
	${ECHO} bin/uwm > ${PLIST}
	${ECHO} lib/X11/uwm/system.uwmrc >> ${PLIST}
	${ECHO} @dirrm lib/X11/uwm >> ${PLIST}

post-install:
	${MKDIR} ${PREFIX}/lib/X11/uwm
	${INSTALL_DATA} ${WRKSRC}/default.uwmrc \
		${PREFIX}/lib/X11/uwm/system.uwmrc

.include <bsd.port.mk>
