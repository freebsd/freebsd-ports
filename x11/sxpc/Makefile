# Created by: jkh@FreeBSD.org
# $FreeBSD$

PORTNAME=	sxpc
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple X Protocol Compressor

USES=		imake
NO_WRKSUBDIR=	yes
EXTRACT_CMD=		${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	| ${SH}

PLIST_FILES=	bin/sxpc man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
