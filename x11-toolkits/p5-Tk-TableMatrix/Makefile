# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tk-TableMatrix
PORTVERSION=	1.23
PORTREVISION=	7
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Table/matrix extension to perl/tk for displaying table formatted data

BUILD_DEPENDS=	p5-Tk>=0:x11-toolkits/p5-Tk
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	X11LIB=${LOCALBASE}/lib X11INC=${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes

# This would conflict with x11-toolkits/p5-Tk
post-install:
	@${RM} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Tk/pTk/extralibs.ld
	@${RMDIR} -p ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Tk/pTk 2>/dev/null || :

.include <bsd.port.mk>
