# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	openmotif
PORTVERSION=	2.3.4
CATEGORIES=	x11-toolkits linux
LIB_DISTFILES=	motif-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Motif toolkit libraries (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

USES=		linux:c7
RPMVERSION=	7.el7
USE_LINUX_RPM=	yes
USE_LINUX=	xorglibs
USE_LDCONFIG=	yes
DESCR=	${.CURDIR}/../open-motif/pkg-descr

post-extract:
		@${RM} -r ${WRKSRC}/etc ${WRKSRC}/usr/bin ${WRKSRC}/usr/include \
			${WRKSRC}/usr/share

.include <bsd.port.mk>
