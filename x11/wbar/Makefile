# New ports collection makefile for:	wbar
# Date created:		2007-01-16
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wbar
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://nivi.interfree.it/distfiles/${PORTNAME}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A quick launch bar for fluxbox, WindowMaker, Xfce, etc

CONFIGURE_ARGS=	--exec-prefix=${PREFIX}

GNU_CONFIGURE=	yes

MAN1=	${PORTNAME}.1 ${PORTNAME}-config.1

USE_EFL=	imlib2
# Disabled: the configure script has a couple of bugs...
#.if !defined(WITHOUT_NLS)
CONFIGURE_ENV=	LIBS=-lintl
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
#.else
#CONFIGURE_ARGS+=	--disable-nls
#PLIST_SUB=	NLS="@comment"
#.endif
USE_GMAKE=	yes
USE_GNOME=	libglade2

.include <bsd.port.mk>
