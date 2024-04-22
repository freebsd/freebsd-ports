PORTNAME=	sessreg
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Manage utmp/wtmp entries for non-init X clients

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg xorg-cat:app
USE_XORG=	x11

PLIST_FILES=	bin/sessreg share/man/man1/sessreg.1.gz
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
