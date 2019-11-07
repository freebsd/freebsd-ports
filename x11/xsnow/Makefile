# Created by: jmz
# $FreeBSD$

PORTNAME=	xsnow
PORTVERSION=	1.42
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://dropmix.xs4all.nl/rick/Xsnow/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create a snowy and Santa-y desktop

BROKEN=		unfetchable

USES=		imake xorg
USE_XORG=	xpm
PLIST_FILES=	bin/xsnow man/man6/xsnow.6.gz

post-configure:
	@${REINPLACE_CMD} \
		-e 's: BINDIR .*:BINDIR=${PREFIX}/bin:' \
		-e 's: MANDIR .*:MANDIR=${PREFIX}/man/man6:' \
		-e 's: MANSUFFIX .*:MANSUFFIX=6:' \
		-e 's/^Makefile::/^Makefile:/' \
			${WRKSRC}/Makefile

.include <bsd.port.mk>
