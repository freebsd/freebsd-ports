# New ports collection makefile for:	gxset
# Date created:		27 December 2001
# Whom:			Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$
#

PORTNAME=	gxset
PORTVERSION=	0.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.seindal.dk/pub/rene/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	petef

MAINTAINER=	bms@spc.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_XPM=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

NOMAN=

.include <bsd.port.mk>
