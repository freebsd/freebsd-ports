# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkchtheme
PORTVERSION=	0.3.1
PORTREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	http://plasmasturm.org/code/gtk-chtheme/
DISTNAME=	gtk-chtheme-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	GTK2 theme changer

USE_BZIP2=	yes
USES=		gmake pkgconfig
USE_GNOME=	gtk20

PLIST_FILES=	bin/gtk-chtheme \
		man/man1/gtk-chtheme.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtk-chtheme ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gtk-chtheme.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
