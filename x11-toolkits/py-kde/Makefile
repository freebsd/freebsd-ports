# New ports collection makefile for:	PyKDE
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	3.16.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-toolkits python kde
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/PyKDE3/ \
		http://freebsd.ricin.com/ports/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lofi
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyKDE-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Bindings for KDE3

RUN_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_KDEBASE_VER=3
USE_PYTHON=	yes
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
CONCAT=		4
ARGS=		-k ${LOCALBASE} -v ${DATADIR} -j ${CONCAT} -d ${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile. ERROR: \
		sipkdecorepart1.cpp:8662: invalid use of undefined type `struct _XDisplay' \
		/usr/X11R6/include/qwindowdefs.h:141: forward declaration of `struct _XDisplay'
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
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${SETENV} python|' \
		${WRKSRC}/postproc

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
