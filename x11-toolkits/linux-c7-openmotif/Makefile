# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	openmotif
PORTVERSION=	2.3.4
PORTREVISION=	1
CATEGORIES=	x11-toolkits linux
LIB_DISTFILES=	motif-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Motif toolkit libraries (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	8.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../open-motif/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/motif-${PORTVERSION}

post-patch:
	@${RM} -r ${WRKSRC}/etc ${WRKSRC}/usr/bin ${WRKSRC}/usr/include \
		${WRKSRC}/usr/share/X11 ${WRKSRC}/usr/share/man

.include <bsd.port.mk>
