# Created by: alepulver
# $FreeBSD$

PORTNAME=	ratmen
PORTVERSION=	2.2.3
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.update.uu.se/~zrajm/programs/ratmen/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple program for displaying a menu in a window

USES=		perl5 xorg
USE_XORG=	x11
USE_PERL5=	build
PLIST_FILES=	bin/ratmen man/man1/ratmen.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ratmen ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ratmen.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
