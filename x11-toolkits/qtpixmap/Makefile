# New ports collection makefile for:	qtpixmap
# Date created:				2003-08-07
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	QtPixmap
PORTVERSION=	0.27
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.kde-look.org/content/files/
DISTNAME=	7043-${PORTNAME}-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Modifed GTK pixmap engine to obtain Theme information from Qt

USE_GNOME=	gtk20
.if !defined(WITHOUT_GTK1)
USE_GNOME+=	gtk12 imlib
PLIST_SUB=	GTK1=""
.else
PLIST_SUB=	GTK1="@comment "
.endif
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/7043-//}
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
