# New ports collection makefile for:	examine
# Date created:		2006-07-18
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	examine
PORTVERSION=	20080223
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Interface for configuring EFL applications

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	ecore ewl
USE_EFL_ECORE=	ipc config

PLIST_FILES=	bin/examine bin/exsh

.include <bsd.port.mk>
