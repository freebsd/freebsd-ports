# New ports collection makefile for:	qtpixmap
# Date created:				2003-08-07
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	QtPixmap
PORTVERSION=	0.28
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.cpdrummond.freeuk.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modifed GTK pixmap engine to obtain Theme information from Qt

USE_GNOME=	gtk20
.if !defined(WITHOUT_GTK1)
USE_GNOME+=	gtk12 imlib
PLIST_SUB=	GTK1=""
.else
PLIST_SUB=	GTK1="@comment "
.endif
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=13
WRKSRC=		${WRKDIR}/${DISTNAME:S/7043-//}
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
