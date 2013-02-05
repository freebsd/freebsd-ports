# Created by: arved
# $FreeBSD$

PORTNAME=	qscintilla
PORTVERSION=	2.7
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/pyqt/QScintilla2/QScintilla-${PORTVERSION}
DISTNAME=	QScintilla-gpl-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	QT port of the Scintilla C++ editor class

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_QT4=	corelib qmake gui

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DESIGNER_PLUGIN DOCS EXAMPLES
OPTIONS_DEFAULT=DESIGNER_PLUGIN DOCS EXAMPLES

DESIGNER_PLUGIN_DESC=	Install plugin for Qt Designer

PLUGINDIR=	${LOCALBASE}/lib/qt4/plugins/designer
WRKDIRS=	Qt4Qt5

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDESIGNER_PLUGIN}
USE_QT4+=	designer
WRKDIRS+=	designer-Qt4
PLIST_SUB+=	DESIGNER_PLUGIN=""
.else
PLIST_SUB+=	DESIGNER_PLUGIN="@comment "
.endif

post-patch:
	${FIND} ${WRKSRC} -name "*.pro" | ${XARGS} ${REINPLACE_CMD} -e \
	    's|%%PREFIX%%|${PREFIX}|g; s|%%DATADIR%%|${DATADIR}|'

do-configure:
.for wrkdir in ${WRKDIRS}
	(cd ${WRKSRC}/${wrkdir} && ${SETENV} ${MAKE_ENV} ${QMAKE})
.endfor

do-build:
.for wrkdir in ${WRKDIRS}
	(cd ${WRKSRC}/${wrkdir} && ${SETENV} ${MAKE_ENV} ${MAKE})
.endfor

do-install:
.for wrkdir in ${WRKDIRS}
	(cd ${WRKSRC}/${wrkdir} && ${SETENV} ${MAKE_ENV} ${MAKE} install)
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc/html-Qt4Qt5 && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/example-Qt4Qt5 && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
