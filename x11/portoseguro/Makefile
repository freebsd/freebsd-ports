# New ports collection makefile for:	portoseguro
# Date created:				2000-10-08
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	portoseguro
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	${PORTNAME}-alpha4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Launch applications by clicking on an icon bar

DEPRECATED=	Upstream disapear and distfile is no more available
EXPIRATION_DATE=	2011-05-01

CONFIGURE_ENV=	GTKCONFIG=${GTK_CONFIG}
USE_AUTOTOOLS=	autoconf213
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_XORG=	xpm
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
.for i in portoseguro portoseguro.conf
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${LOCALBASE}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
