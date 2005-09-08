# New ports collection makefile for:	PyQt
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$

PORTNAME=	qt
PORTVERSION=	3.15
PORTREVISION=	
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/PyQt/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyQt-x11-gpl-3.15

MAINTAINER=	danny@ricin.com
COMMENT=	Python bindings for the Qt toolkit

LIB_DEPENDS=	qscintilla.6:${PORTSDIR}/x11-toolkits/qscintilla
BUILD_DEPENDS=	${LOCALBASE}/bin/sip:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_QT_VER=	3
USE_PYTHON=	yes
USE_REINPLACE=	yes

OPTIONS=	DEBUG "Enable debugging symbols" off \
		DOCS "Install documentation" on \
		EXAMPLES "Install examples" on \
		OPENGL "Enable OpenGL support" on \
		TRACING	"Enable tracing in generated code" off

DATADIR=	${PREFIX}/share/py-sip
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
ARGS=		-b ${PREFIX}/bin -d ${PYTHONPREFIX_SITELIBDIR} \
		-o ${X11BASE}/lib -v ${DATADIR}

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
ARGS+=		-u
.endif
.if defined(NOPORTDOCS) || defined(WITHOUT_DOCS)
PLIST_SUB+=	DOCS="@comment "
.else
PLIST_SUB+=	DOCS=""
.endif
.if defined(WITHOUT_EXAMPLES)
PLIST_SUB+=     EXAMPLES="@comment "
.else
PLIST_SUB+=	EXAMPLES=""
.endif
.if exists(${X11BASE}/include/qgl.h) && !defined(WITHOUT_OPENGL)
PLIST_SUB+=	OPENGL=""
.else
PLIST_SUB+=	OPENGL="@comment "
pre-configure:
	@( ${RM} -r ${WRKSRC}/sip/qtgl && ${ECHO} "OpenGL support is disabled" )
.endif
.if defined(WITH_TRACING)
ARGS+=		-r
.endif

do-configure:
	( cd ${WRKSRC} && ${ECHO} "yes" | ${PYTHON_CMD} configure.py ${ARGS} )

post-build:
.if !defined(WITHOUT_EXAMPLES)
	( cd ${WRKSRC} && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py examples3 )
.endif

post-install:
	( ${PYTHON_CMD} -c "import pyqtconfig" && \
		${PYTHON_CMD} -O -c "import pyqtconfig" )
.if !defined(NOPORTDOCS) && !defined(WITHOUT_DOCS)
	( cd ${WRKSRC} && \
		${MKDIR} -m 0755 ${DOCSDIR} && \
		${INSTALL_DATA} ChangeLog NEWS README doc/* ${DOCSDIR} )
.endif
.if !defined(WITHOUT_EXAMPLES)
	( cd ${WRKSRC}/examples3 && \
		${MKDIR} -m 0755 ${EXAMPLESDIR}/SQL ${EXAMPLESDIR}/canvas \
			${EXAMPLESDIR}/i18n ${EXAMPLESDIR}/webbrowser && \
		${INSTALL_DATA} README *.py *.pyc *.png *.gif *.bmp *.xpm \
			${EXAMPLESDIR} && \
		${INSTALL_DATA} SQL/* ${EXAMPLESDIR}/SQL && \
		${INSTALL_DATA} canvas/* ${EXAMPLESDIR}/canvas && \
		${INSTALL_DATA} i18n/* ${EXAMPLESDIR}/i18n && \
		${INSTALL_DATA} webbrowser/* ${EXAMPLESDIR}/webbrowser )
.endif

.include <bsd.port.post.mk>
