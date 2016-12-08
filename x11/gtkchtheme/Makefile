# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkchtheme
PORTVERSION=	0.3.1
PORTREVISION=	11
CATEGORIES=	x11
MASTER_SITES=	http://plasmasturm.org/code/gtk-chtheme/
DISTNAME=	gtk-chtheme-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 theme changer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pkgconfig tar:bzip2
USE_GNOME=	gtk20

PLIST_FILES=	bin/gtk-chtheme \
		man/man1/gtk-chtheme.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtk-chtheme ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gtk-chtheme.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
