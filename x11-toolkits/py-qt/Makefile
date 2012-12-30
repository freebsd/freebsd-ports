# New ports collection makefile for:	PyQt
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$

PORTNAME=	qt
PORTVERSION=	3.18.2
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://www.riverbankcomputing.com/static/Downloads/PyQt3/ \
		http://ns.ael.ru/~fluffy.khv/pyqt/PyQt3/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyQt-x11-gpl-${PORTVERSION}-snapshot-20091119

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for the Qt toolkit

LIB_DEPENDS=	qscintilla.7:${PORTSDIR}/x11-toolkits/qscintilla
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip \
		qmake:${PORTSDIR}/devel/qmake

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_QT_VER=	3
USE_PYTHON=	2.5+

OPTIONS_DEFINE=	DEBUG OPENGL TRACING EXAMPLES DOCS
OPTIONS_DEFAULT=	OPENGL
TRACING_DESC=	Enable tracing in generated code

DATADIR=	${PREFIX}/share/py-sip
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
SPEC=		${LOCALBASE}/share/qt/mkspecs/freebsd-g++
ARGS=		-b ${PREFIX}/bin -d ${PYTHON_SITELIBDIR}\
		-o ${LOCALBASE}/lib -v ${DATADIR}
MODULES=	qt qtcanvas qtnetwork qttable qtxml qtui qtsql qtext

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
ARGS+=		-u
.endif
.if exists(${LOCALBASE}/include/qgl.h) && ${PORT_OPTIONS:MOPENGL}
PLIST_SUB+=	OPENGL=""
MODULES+=	qtgl
.else
PLIST_SUB+=	OPENGL="@comment "
pre-configure:
	@${RM} -r ${WRKSRC}/sip/qtgl && ${ECHO_CMD} && ${ECHO_CMD}\
		"**  OpenGL is disabled (chosen here or your Qt3 has no OpenGL support) **"\
		&& ${ECHO_CMD}
.endif
.if ${PORT_OPTIONS:MTRACING}
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
.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKSRC} &&\
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py examples3
.endif

post-install:
	cd ${PYTHON_SITELIBDIR} &&\
		${PYTHON_CMD} -c "import pyqtconfig" &&\
		${PYTHON_CMD} -O -c "import pyqtconfig"
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} &&\
		${MKDIR} ${DOCSDIR} &&\
		${INSTALL_DATA} ChangeLog NEWS README doc/* ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
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

.include <bsd.port.mk>
