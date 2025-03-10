PORTNAME=	xascii
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://cschubert.com/distfiles/ \
		LOCAL/cy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Display an ASCII table in decimal, octal, and hexadecimal

USES=		imake xorg
USE_XORG=	x11 xt xaw

MAKE_ARGS=	PREFIX=${PREFIX}
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/xascii share/man/man1/xascii.1.gz

.include <bsd.port.mk>
