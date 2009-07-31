# New ports collection makefile for:	PyKDE
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	${PYKDE3_VERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-toolkits python kde
MASTER_SITES=	${MASTER_SITES_PYKDE3} ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lofi
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYKDE3_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for KDE3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}qt>=${PYQT3_VERSION}:${PORTSDIR}/x11-toolkits/py-qt
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_KDEBASE_VER=3
USE_PYTHON=	2.5+
USE_BZIP2=	yes

OPTIONS=	DEBUG "Enable debugging symbols" off \
		TRACING "Enable tracing in generated code" off

DATADIR=	${PREFIX}/share/py-sip
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
ARGS=		-i -k ${LOCALBASE} -v ${DATADIR} -d ${PYTHON_SITELIBDIR}

.include "../../devel/py-sip/files/bsd.pyqt.mk"
.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
ARGS+=		-u
.endif
.if defined(WITH_TRACING)
ARGS+=		-r
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/python|${SETENV} python|'\
		${WRKSRC}/postproc

do-configure:
	cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${ARGS}

post-configure:
	for item in dcop kdecore kdefx kdeui kio kresources kabc kutils kfile\
		kparts khtml kspell kdeprint kmdi ; do\
		${REINPLACE_CMD} -e 's|mkspecs/freebsd-g++|share/qt/mkspecs/freebsd-g++|'\
			-e 's|CC = cc|CC = ${CC}|'\
			-e 's|CXX = c++|CXX = ${CXX}|'\
			-e 's|LINK = c++|LINK = ${CXX}|'\
			${WRKSRC}/$${item}/Makefile ; done

post-build:
	cd ${WRKSRC} && ${MKDIR} tmp &&\
		${CP} pykdeconfig.py extensions/* tmp &&\
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py tmp
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC} &&\
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py examples
.endif
	${REINPLACE_CMD} -e 's|ln.*||g' ${WRKSRC}/Makefile

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/kdepyuic ${PREFIX}/bin &&\
		${INSTALL_DATA} ${WRKSRC}/tmp/*.pyc ${PYTHON_SITELIBDIR}
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc &&\
		${MKDIR} ${DOCSDIR}/classref ${DOCSDIR}/images &&\
		${INSTALL_DATA} kde.css *.html ${DOCSDIR} &&\
		${INSTALL_DATA} images/* ${DOCSDIR}/images &&\
		${INSTALL_DATA} classref/*.html ${DOCSDIR}/classref &&\
		cd classref &&\
		for i in `ls | ${GREP} -v allclasses | ${GREP} -v glossary |\
			${GREP} -v index` ; do\
			${MKDIR} ${DOCSDIR}/classref/$${i} &&\
			${INSTALL_DATA} $${i}/*.html\
			${DOCSDIR}/classref/$${i} ; done
.endif
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC}/examples &&\
		${MKDIR} ${EXAMPLESDIR}/uimodules &&\
		${INSTALL_DATA} uimodules/* ${EXAMPLESDIR}/uimodules &&\
		${INSTALL_DATA} README *.dtd *.p* *.rc *.ui* ${EXAMPLESDIR}
	cd ${WRKSRC}/templates &&\
		${MKDIR} ${EXAMPLESDIR}/templates/annotated\
			${EXAMPLESDIR}/templates/basic &&\
		${INSTALL_DATA} annotated/* ${EXAMPLESDIR}/templates/annotated &&\
		${INSTALL_DATA} basic/* ${EXAMPLESDIR}/templates/basic
.endif

.include <bsd.port.post.mk>
