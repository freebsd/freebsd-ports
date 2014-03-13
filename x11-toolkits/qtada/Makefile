# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qtada
PORTVERSION=	3.2.0.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://download.qtada.com/
DISTNAME=	${PORTNAME}-gpl-3.2.0-20120708-3871

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Ada2005 language bindings to Qt4 framework

LICENSE=	GPLv2

BUILD_DEPENDS=	gprbuild>=20120510:${PORTSDIR}/devel/gprbuild \
		asis>=2011:${PORTSDIR}/lang/asis

USES=		ada gmake pkgconfig
GNU_CONFIGURE=	yes
USE_QT4=	corelib gui xml designer sql opengl webkit
NO_MTREE=	yes

#CONFIGURE_ARGS=	--with-gtkada=NO

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share
	${MV} ${STAGEDIR}${PREFIX}/examples ${STAGEDIR}${PREFIX}/share/
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | \
	   ${SORT} -r | ${SED} -e '/lib\/gnat$$/d' -e '/share\/doc$$/d' \
	   -e '/share\/gps$$/d' -e '/share\/gps\/plug-ins$$/d' \
	   -e '/share\/gprconfig$$/d' -e 's/^/@dirrm /g' \
	   >> ${TMPPLIST}
	@echo "@unexec rmdir %D/lib/gnat 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/doc 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/gprconfig 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/gps/plug-ins 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/gps 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
