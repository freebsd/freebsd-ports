# Created by: ijliao
# $FreeBSD$

PORTNAME=	xstroke
PORTVERSION=	0.5.12
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	http://ftp.gwdg.de/pub/linux/handhelds/projects/xstroke/release-0.5/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fullscreen gesture recognition

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison imake localbase
USE_XORG=	xft x11 xext xi xtst

PLIST_FILES=	bin/xstroke %%ETCDIR%%/alphabet man/man1/xstroke.1.gz

CFLAGS+=	-I.
LDFLAGS+=	-lpthread

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/etc/Imakefile
	@${REINPLACE_CMD} -e "s,etc/,${PREFIX}/etc/,g" ${WRKSRC}/args.h

.include <bsd.port.mk>
