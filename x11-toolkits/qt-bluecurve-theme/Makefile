# New ports collection makefile for:    bluecurve-unified
# Date created:         3 October 2002
# Whom:                 Eugeney Ryzhyk
#
# $FreeBSD$
#

PORTNAME=	qt-bluecurve-theme
PORTVERSION=	0.47
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	8.0/en/os/i386/SRPMS
DISTFILES=	redhat-artwork-${PORTVERSION}-${RH_SUBVERSION}.src.rpm

MAINTAINER=	rzheka@users.sourceforge.net

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio \
		libtool:${PORTSDIR}/devel/libtool

WRKSRC= 	${WRKDIR}/redhat-artwork-${PORTVERSION}
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

RH_SUBVERSION=	3

USE_QT_VER=	3
THEMES_SUBDIRS =	${WRKSRC}/art/qt/Bluecurve

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@if ! (cd ${WRKDIR} && rpm2cpio ${_DISTDIR}/${DISTFILES} | cpio -i redhat-artwork-${PORTVERSION}.tar.gz 2>/dev/null && ${GZIP_CMD} -dc redhat-artwork-${PORTVERSION}.tar.gz | tar -xf - && ${RM} redhat-artwork-${PORTVERSION}.tar.gz);\
		then \
			exit 1; \
		fi
	${CP} ${FILESDIR}/Makefile-qt3 ${WRKSRC}/art/qt/Bluecurve/Makefile

post-patch:
	@${REINPLACE_CMD} -e 's#-O2#${CFLAGS}#' ${WRKSRC}/art/qt/Bluecurve/Makefile

do-build:
	@for theme_dir in ${THEMES_SUBDIRS};do \
		(cd $$theme_dir; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}); \
	done
do-install:
	@${MKDIR} ${PREFIX}/plugins/styles && ${CHMOD} a+rx ${PREFIX}/plugins/styles
	@${INSTALL_PROGRAM} ${WRKSRC}/art/qt/Bluecurve/.libs/bluecurve.so ${PREFIX}/plugins/styles

.include <bsd.port.mk>
