# New ports collection makefile for:	portoseguro
# Date created:				2000-10-08
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	portoseguro
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	${PORTNAME}-alpha4

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Launch applications by clicking on an icon bar

CONFIGURE_ENV=	GTKCONFIG=${GTK_CONFIG}
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
USE_XPM=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
.for i in portoseguro portoseguro.conf
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${X11BASE}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${X11BASE}/share/doc/portoseguro
	${INSTALL_DATA} ${WRKSRC}/README ${X11BASE}/share/doc/portoseguro
.endif

.include <bsd.port.mk>
