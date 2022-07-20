PORTNAME=	Tk-TableMatrix
PORTVERSION=	1.26
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Table/matrix extension to perl/tk for displaying table formatted data

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Tk>=0:x11-toolkits/p5-Tk

USES=		dos2unix perl5
USE_PERL5=	configure

CONFIGURE_ARGS=	X11LIB=${LOCALBASE}/lib X11INC=${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Tk/TableMatrix/TableMatrix.so
# This would conflict with x11-toolkits/p5-Tk
	${RM} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Tk/pTk/extralibs.ld
	${RMDIR} -p ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Tk/pTk 2>/dev/null || :

.include <bsd.port.mk>
