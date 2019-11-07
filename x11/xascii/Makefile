# Created by: Cy Schubert <cy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xascii
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://komquats.com/distfiles/ \
		http://people.freebsd.org/~cy/distfiles/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Display an ASCII table in decimal, octal, and hexadecimal

USES=		imake xorg
USE_XORG=	x11 xt xaw

MAKE_ARGS=	PREFIX=${PREFIX}
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/xascii man/man1/xascii.1.gz

.include <bsd.port.mk>
