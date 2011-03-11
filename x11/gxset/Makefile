# New ports collection makefile for:	gxset
# Date created:		27 December 2001
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gxset
PORTVERSION=	0.3
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	petef

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK frontend for xset(1)

DEPRECATED=	Upstream disapear and distfile is no more available
EXPIRATION_DATE=	2011-05-01

USE_GNOME=	gtk12
USE_XORG=	xpm
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

NOMAN=

PLIST_FILES=	bin/gxset
PLIST_FILES+=	share/locale/cs/LC_MESSAGES/gxset.mo
PLIST_FILES+=	share/locale/da/LC_MESSAGES/gxset.mo
PLIST_FILES+=	share/locale/ja/LC_MESSAGES/gxset.mo

.include <bsd.port.mk>
