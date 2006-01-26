# New ports collection makefile for:	PyKDE
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	3.15.0
PORTEPOCH=	1
CATEGORIES=	x11-toolkits python kde
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/PyKDE3/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyKDE-snapshot20060122

MAINTAINER=	danny@ricin.com
COMMENT=	Python Bindings for KDE3

RUN_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_KDELIBS_VER=3
USE_PYTHON=	yes
USE_REINPLACE=	yes
NO_FILTER_SHLIBS=	yes

OPTIONS=	DEBUG "Enable debugging symbols" off \
		DOCS "Install documentation" on \
		EXAMPLES "Install examples" on \
		TEMPLATES "Install application templates" on \
		TRACING "Enable tracing in generated code" off

DATADIR=	${PREFIX}/share/py-sip
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
ARGS=		-k ${LOCALBASE} -v ${DATADIR} -d ${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
.if ${ARCH} == "sparc64"
ARGS+=		-j 3
.endif
ARGS+=		-j 2
.endif
.if defined(WITH_DEBUG)
ARGS+=		-u
.endif
.if defined(NOPORTDOCS) || defined(WITHOUT_DOCS)
PLIST_SUB+=	DOCS="@comment "
.else
PLIST_SUB+=	DOCS=""
.endif
.if defined(WITHOUT_EXAMPLES)
PLIST_SUB+=	EXAMPLES="@comment "
.else
PLIST_SUB+=	EXAMPLES=""
.endif
.if defined(WITHOUT_TEMPLATES)
PLIST_SUB+=	TEMPLATES="@comment "
.else
PLIST_SUB+=	TEMPLATES=""
.endif
.if defined(WITH_TRACING)
ARGS+=		-r
.endif

post-patch:
	( ${REINPLACE_CMD} -e 's|/usr/bin/python|${SETENV} python|' \
		${WRKSRC}/postproc )
.if !defined(NOPORTDOCS) && !defined(WITHOUT_DOCS)
	( cd ${WRKSRC}/doc/classref && \
		${REINPLACE_CMD} -e 's|../allclasses.html|allclasses.html|' \
			allclasses.html && \
		for i in `ls */*.html`; do \
			${REINPLACE_CMD} -e \
			's|file:/home/jim/PyKDE350/doc/classref/index.html|../../index.html|' \
			$${i} ; done && \
		for i in allclasses.html index.html; do \
			${REINPLACE_CMD} -e \
			's|file:/home/jim/PyKDE350/doc/classref/index.html|../index.html|' \
			$${i} ; done )
.endif

do-configure:
	( cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${ARGS} )

post-build:
	( cd ${WRKSRC} && ${MKDIR} tmp && \
		${CP} pykdeconfig.py extensions/* tmp && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py tmp )
.if !defined(WITHOUT_EXAMPLES)
	( cd ${WRKSRC} && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py examples )
.endif

post-install:
	( ${INSTALL_SCRIPT} ${WRKSRC}/contrib/kdepyuic ${PREFIX}/bin && \
		${INSTALL_DATA} ${WRKSRC}/tmp/*.pyc ${PYTHONPREFIX_SITELIBDIR} )
.if !defined(NOPORTDOCS) && !defined(WITHOUT_DOCS)
	( cd ${WRKSRC}/doc && \
		${MKDIR} -m 0755 ${DOCSDIR}/classref ${DOCSDIR}/images && \
		${INSTALL_DATA} kde.css *.html ${DOCSDIR} && \
		${INSTALL_DATA} images/* ${DOCSDIR}/images && \
		${INSTALL_DATA} classref/*.html ${DOCSDIR}/classref && \
		cd classref && \
		for i in `ls | ${GREP} -v allclasses | ${GREP} -v glossary | \
			${GREP} -v index` ; do \
			${MKDIR} -m 0755 ${DOCSDIR}/classref/$${i} && \
			${INSTALL_DATA} $${i}/*.html \
			${DOCSDIR}/classref/$${i} ; done )
.endif
.if !defined(WITHOUT_EXAMPLES)
	( cd ${WRKSRC}/examples && \
		${MKDIR} -m 0755 ${EXAMPLESDIR}/uimodules && \
		${INSTALL_DATA} uimodules/* ${EXAMPLESDIR}/uimodules && \
		${INSTALL_DATA} README *.dtd *.p* *.rc *.ui* ${EXAMPLESDIR} )
.endif
.if !defined(WITHOUT_TEMPLATES)
	( cd ${WRKSRC}/templates && \
		${MKDIR} -m 0755 ${EXAMPLESDIR}/templates/annotated \
			${EXAMPLESDIR}/templates/basic && \
		${INSTALL_DATA} annotated/* ${EXAMPLESDIR}/templates/annotated && \
		${INSTALL_DATA} basic/* ${EXAMPLESDIR}/templates/basic )
.endif

.include <bsd.port.post.mk>
