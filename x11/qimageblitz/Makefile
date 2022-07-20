PORTNAME=	qimageblitz
PORTVERSION=	0.1.0.${SVN_REVISION} # a made-up version also used in some linux distros, otherwise we need to add PORTEPOCH
CATEGORIES=	x11

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical effects and filters library for Qt5

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

FETCH_DEPENDS=	svn:devel/subversion

USES=		cmake compiler:c++11-lang qt:5
USE_LDCONFIG=	yes
USE_QT=		core gui widgets qmake_build buildtools_build
USE_CXXSTD=	gnu++98

SVN_URL=	svn://anonsvn.kde.org/home/kde/trunk/kdesupport/qimageblitz
SVN_REVISION=	1548172

do-fetch:
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}" ]; then \
	  ${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
	  cd ${DISTDIR}/${DIST_SUBDIR} && \
	    svn co -r ${SVN_REVISION} ${SVN_URL} ${PORTNAME}-${DISTVERSIONFULL} && \
	    (cd ${PORTNAME}-${DISTVERSIONFULL} && ${RM} -r .svn) && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -print0 | LC_ALL=C ${SORT} -z | \
	        ${TAR} czf ${PORTNAME}-${DISTVERSIONFULL}${EXTRACT_SUFX} --format=bsdtar --uid 0 --gid 0 --options gzip:!timestamp --no-recursion --null -T - && \
	    ${RM} -r ${PORTNAME}-${DISTVERSIONFULL}; \
	fi

.include <bsd.port.mk>
