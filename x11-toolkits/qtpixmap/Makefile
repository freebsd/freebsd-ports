# New ports collection makefile for:	qtpixmap
# Date created:				2003-08-07
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	qtpixmap
PORTVERSION=	0.28
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.cpdrummond.freeuk.com/
DISTNAME=	QtPixmap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modifed GTK pixmap engine to obtain Theme information from Qt

USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
WRKSRC=		${WRKDIR}/${DISTNAME:S/7043-//}

.if !defined(WITHOUT_GTK1)
USE_GNOME+=	gtk12 imlib
PLIST_SUB=	GTK1=""
.else
PLIST_SUB=	GTK1="@comment "
.endif

.include <bsd.port.mk>
