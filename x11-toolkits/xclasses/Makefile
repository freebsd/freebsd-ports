# New ports collection makefile for:	xclasses
# Date created:		2000-10-01
# Whom:			Trevor Johnson <trevor@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	xclasses
PORTVERSION=	1.1.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://fsai.fh-trier.de/~schmitzj/Xclasses/arc/
DISTNAME=	Xclasses-public-${PORTVERSION}.src

MAINTAINER=	trevor@FreeBSD.org

USE_X_PREFIX=	yes
PLIST_SUB=	VERSION="${PORTVERSION}"
WRKSRC=		${WRKDIR}/xclasses

post-patch:
	@${PERL} -pi -e "s=X11BASE=${X11BASE}=g" ${WRKSRC}/build \
		${WRKSRC}/System/ARules.FreeBSD

do-build:
	@cd ${WRKSRC} && ${SH} build all

do-install:
	@cd ${WRKSRC} && ${SH} build install
	@${INSTALL_SCRIPT} ${WRKSRC}/setenvxc ${PREFIX}/bin

.include <bsd.port.mk>
