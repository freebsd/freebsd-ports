# New ports collection makefile for:	qtpixmap
# Date created:				2003-08-07
# Whom:					arved
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/qtpixmap/Makefile,v 1.2 2006/09/30 01:16:13 mezz Exp $
#

PORTNAME=	qtpixmap
PORTVERSION=	0.28
PORTREVISION=	13
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.cpdrummond.freeuk.com/
DISTNAME=	QtPixmap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modifed GTK pixmap engine to obtain Theme information from Qt

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2011-10-31

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/7043-//}

.if defined(WITH_GTK1)
USE_GNOME+=	gtk12 imlib
PLIST_SUB=	GTK1=""
.else
PLIST_SUB=	GTK1="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e "s,echo aout, echo elf," ${WRKSRC}/configure

.include <bsd.port.mk>
