# New ports collection makefile for:	gtkchtheme
# Date created:				18 June 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkchtheme
PORTVERSION=	0.3.1
PORTREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://plasmasturm.org/code/gtk-chtheme/
DISTNAME=	gtk-chtheme-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 theme changer

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20

PLIST_FILES=	bin/gtk-chtheme
MAN1=		gtk-chtheme.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtk-chtheme ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gtk-chtheme.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
