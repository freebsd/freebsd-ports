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

INSTALLS_SHLIB=	yes
PLIST_SUB=	VERSION="${PORTVERSION}"
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
WRKSRC=		${WRKDIR}/xclasses

post-patch:
.for file in build System/ARules.FreeBSD
	@${PERL} -pi \
		-e "s|%%CXX%%|${CXX}|g;" \
		-e "s|%%CXXFLAGS%%|${CXXFLAGS}|g;" \
		-e "s|%%X11BASE%%|${X11BASE}|g;" ${WRKSRC}/${file}
.endfor

do-build:
	@cd ${WRKSRC} && ${SH} build all

do-install:
	@cd ${WRKSRC} && ${SH} build install
	@${INSTALL_SCRIPT} ${WRKSRC}/setenvxc ${PREFIX}/bin

.include <bsd.port.mk>
