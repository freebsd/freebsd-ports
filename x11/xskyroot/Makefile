PORTNAME=	xskyroot
PORTVERSION=	920428
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/news/fj.sources/V10/
DISTNAME=	1079
EXTRACT_SUFX=	.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Realtime sky drawer for X root window

LICENSE=	NONE

USES=		imake xorg
USE_XORG=	x11

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	| ${SED} -e "/^...bin.sh/,/exit 0/!d" | ${SH}

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/xskyroot

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
