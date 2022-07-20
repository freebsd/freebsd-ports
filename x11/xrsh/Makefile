PORTNAME=	xrsh
PORTVERSION=	5.92
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://jjd.com/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.shar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Launcher which starts an X program on a remote machine

USES=		imake
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=

PLIST_FILES=	bin/xrsh bin/xrlogin \
		man/man1/xrsh.1.gz man/man1/xrlogin.1.gz

.include <bsd.port.mk>
