# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	openmotif
PORTVERSION=	2.3.3
DISTVERSIONSUFFIX=	-9.el6
PORTREVISION=	4
CATEGORIES=	x11-toolkits linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Motif toolkit libraries (Linux CentOS ${LINUX_DIST_VER})

DESCR=		${.CURDIR}/../open-motif/pkg-descr
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${RM} -r ${WRKSRC}/etc ${WRKSRC}/usr/bin ${WRKSRC}/usr/include \
		${WRKSRC}/usr/share/X11 ${WRKSRC}/usr/share/man

.include <bsd.port.mk>
