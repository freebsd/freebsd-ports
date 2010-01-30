# New ports collection makefile for:	PyQt
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$

PORTNAME=	qt
PORTVERSION=	${PYQT3_VERSION}
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITES_PYQT3}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYQT3_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt toolkit

LIB_DEPENDS=	qscintilla.7:${PORTSDIR}/x11-toolkits/qscintilla
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip \
		qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
USE_PYTHON=	2.5+

OPTIONS=	DEBUG "Enable debugging symbols" off \
		OPENGL "Enable OpenGL support" on \
		TRACING	"Enable tracing in generated code" off

DATADIR=	${PREFIX}/share/py-sip
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
SPEC=		${LOCALBASE}/share/qt/mkspecs/freebsd-g++
ARGS=		-b ${PREFIX}/bin -d ${PYTHON_SITELIBDIR}\
		-o ${LOCALBASE}/lib -v ${DATADIR}
MODULES=	qt qtcanvas qtnetwork qttable qtxml qtui qtsql qtext

.include "../../devel/py-sip/files/bsd.pyqt.mk"
.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
ARGS+=		-u
.endif
.if exists(${LOCALBASE}/include/qgl.h) && !defined(WITHOUT_OPENGL)
PLIST_SUB+=	OPENGL=""
MODULES+=	qtgl
.else
PLIST_SUB+=	OPENGL="@comment "
pre-configure:
	@${RM} -r ${WRKSRC}/sip/qtgl && ${ECHO_CMD} && ${ECHO_CMD}\
		"**  OpenGL is disabled (chosen here or your Qt3 has no OpenGL support) **"\
		&& ${ECHO_CMD}
.endif
.if defined(WITH_TRACING)
ARGS+=		-r
.endif

do-configure:
	cd ${WRKSRC} && ${ECHO} "yes" |\
		${SETENV} QTDIR=${QT_PREFIX} QMAKESPEC=${SPEC}\
		${PYTHON_CMD} configure.py ${ARGS}

post-configure:
.for item in ${MODULES}
	${REINPLACE_CMD} -e 's|mkspecs/freebsd-g++|share/qt/mkspecs/freebsd-g++|'\
		-e 's|CC = cc|CC = ${CC}|'\
		-e 's|CXX = c++|CXX = ${CXX}|'\
		-e 's|LINK = c++|LINK = ${CXX}|'\
		${WRKSRC}/${item}/Makefile
.endfor

post-build:
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC} &&\
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py examples3
.endif

post-install:
	cd ${PYTHON_SITELIBDIR} &&\
		${PYTHON_CMD} -c "import pyqtconfig" &&\
		${PYTHON_CMD} -O -c "import pyqtconfig"
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} &&\
		${MKDIR} ${DOCSDIR} &&\
		${INSTALL_DATA} ChangeLog NEWS README doc/* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC}/examples3 &&\
		${MKDIR} ${EXAMPLESDIR}/SQL ${EXAMPLESDIR}/canvas\
			${EXAMPLESDIR}/i18n ${EXAMPLESDIR}/webbrowser &&\
		${INSTALL_DATA} README *.py *.pyc *.png *.gif *.bmp *.xpm\
			${EXAMPLESDIR} &&\
		${INSTALL_DATA} SQL/* ${EXAMPLESDIR}/SQL &&\
		${INSTALL_DATA} canvas/* ${EXAMPLESDIR}/canvas &&\
		${INSTALL_DATA} i18n/* ${EXAMPLESDIR}/i18n &&\
		${INSTALL_DATA} webbrowser/* ${EXAMPLESDIR}/webbrowser
.endif

.include <bsd.port.post.mk>
