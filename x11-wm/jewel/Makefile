# New ports collection makefile for:	jewel
# Date created:				2002-05-26
# Whom:					trevor
# based in part on the aewm++ port by ijliao
#
# $FreeBSD$
#

PORTNAME=	jewel
PORTVERSION=	0.12.31
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.mjr.dsl.pipex.com/comp/

MAINTAINER=	trevor@FreeBSD.org

BROKEN=		"Does not fetch"

ALL_TARGET=	aewm++
DOCDIR=		share/doc/${PORTNAME}
DOCS=		Changelog Changelog.DLR Changelog.jewel INSTALL LICENSE README
PLIST=		${WRKDIR}/pkg-plist
USE_X_PREFIX=	yes
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e "s,^CC,#CC,g ; s,^CFLAGS,#CFLAGS,g ; \
		s,^prefix,#prefix,g ; s,prefix,PREFIX,g ; \
		s,CC,CXX,g ; s,CFLAGS,CXXFLAGS,g" ${WRKSRC}/Makefile

pre-install:
	${ECHO_CMD} bin/jewel > ${PLIST}
.if !defined(NOPORTDOCS)
.for ii in ${DOCS}
	${ECHO_CMD} ${DOCDIR}/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aewm++ ${PREFIX}/bin/jewel
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${PREFIX}/${DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
