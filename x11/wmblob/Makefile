# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	wmblob
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://BSDforge.com/projects/source/x11/wmblob/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Shows moving blobs

USE_XORG=	xpm
USE_GNOME=	gtk20
USES=		pkgconfig tar:xz
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/wmblob man/man1/wmblob.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/wmblob ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/wmblob.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
