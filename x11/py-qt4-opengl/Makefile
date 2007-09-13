# New ports collection makefile for:	py-qt4-opengl
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	opengl
PORTVERSION=	4.3
PORTREVISION=	# zero
CATEGORIES=	x11 devel python
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/PyQt4/GPL/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	PyQt-x11-gpl-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Python bindings for the Qt4 toolkit, QtOpenGL module

BUILD_DEPENDS=	${LOCALBASE}/bin/sip:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui

HAS_CONFIGURE=	yes
USE_PYTHON=	2.5+
USE_QT_VER=	4
QT_COMPONENTS=	opengl qmake

OPTIONS=	API		"Install QtOpenGL API for QScintilla2" on \
		DEBUG		"Enable debugging in generated code" off \
		SIPFILES	"Install the QtOpenGL SIP files" on \
		TRACING		"Enable tracing in generated code" off

PATCHDIR=	${PORTSDIR}/devel/py-qt4-core/files
OPTIONSFILE=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
SIPDIR=		${PREFIX}/share/py-sip
CONFIGURE_ENV+=	PYQT4_COMPONENT="${PORTNAME}"
ARGS=		-b ${PREFIX}/bin\
		-d ${PYTHON_SITELIBDIR}\
		-q ${QT_PREFIX}/bin/qmake-qt4

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
ARGS+=		--debug
.endif
.if defined(WITHOUT_API)
ARGS+=		--no-qsci-api
PLIST_SUB+=	API="@comment "
PLIST_SUB+=	APIFILE="@comment "
.else
LIB_DEPENDS+=	qscintilla2.2:${PORTSDIR}/devel/qscintilla2
ARGS+=		--qsci-api
PLIST_SUB+=	API=""
PLIST_SUB+=	APIFILE="share/qt4/qsci/api/python/QtOpenGL.api"
.endif
.if defined(WITHOUT_SIPFILES)
ARGS+=		--no-sip-files
PLIST_SUB+=	SIPFILES="@comment "
PLIST_SUB+=	SIPDIR="@comment "
.else
ARGS+=		--sipdir ${SIPDIR}
PLIST_SUB+=	SIPFILES=""
PLIST_SUB+=	SIPDIR="share/py-sip"
.endif
.if defined(WITH_TRACING)
ARGS+=		--trace
.endif
ARGS+=		--enable QtOpenGL

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV}\
		${PYTHON_CMD} configure.py ${ARGS}

post-configure:
	${REINPLACE_CMD} -e 's|mkspecs/freebsd-g++|share/qt4/mkspecs/freebsd-g++|'\
		-e 's|CC = cc|CC = ${CC}|'\
		-e 's|CXX = c++|CXX = ${CXX}|'\
		-e 's|LINK = c++|LINK = ${CXX}|'\
		${WRKSRC}/QtOpenGL/Makefile

.include <bsd.port.post.mk>
