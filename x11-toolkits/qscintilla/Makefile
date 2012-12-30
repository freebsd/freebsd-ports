# New ports collection makefile for:	qscintilla
# Date created:				2003-08-02
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	qscintilla
PORTVERSION=	1.7.1
PORTREVISION=	8
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.riverbankcomputing.com/static/Downloads/QScintilla1/ \
		http://ns.ael.ru/~fluffy.khv/pyqt/QScintilla1/
DISTNAME=	QScintilla-1.71-gpl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QT port of the Scintilla C++ editor class

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}"
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DESIGNER_PLUGIN DOCS EXAMPLES LANG_DE LANG_FR LANG_PTBR LANG_RU
OPTIONS_DEFAULT=	DESIGNER_PLUGIN DOCS EXAMPLES LANG_DE LANG_FR LANG_PTBR LANG_RU

DESIGNER_PLUGIN_DESC=	Install plugin for Qt Designer
LANG_DE_DESC=		Install German translation
LANG_FR_DESC=		Install French translation
LANG_PTBR_DESC=		Install Brazilian Portuguese translation
LANG_RU_DESC=		Install Russian translation

QMAKE=		${LOCALBASE}/bin/qmake
SPEC=		${LOCALBASE}/share/qt/mkspecs/freebsd-g++
PLUGINDIR=	${LOCALBASE}/lib/plugins/designer

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=	DOCS=""
.else
PLIST_SUB+=	DOCS="@comment "
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif
.if ${PORT_OPTIONS:MDESIGNER_PLUGIN}
PLIST_SUB+=	DESIGNER_PLUGIN=""
.else
PLIST_SUB+=	DESIGNER_PLUGIN="@comment "
.endif
.if ${PORT_OPTIONS:MLANG_DE}
PLIST_SUB+=	LANG_DE=""
.else
PLIST_SUB+=	LANG_DE="@comment "
.endif
.if ${PORT_OPTIONS:MLANG_FR}
PLIST_SUB+=	LANG_FR=""
.else
PLIST_SUB+=	LANG_FR="@comment "
.endif
.if ${PORT_OPTIONS:MLANG_PTBR}
PLIST_SUB+=	LANG_PTBR=""
.else
PLIST_SUB+=	LANG_PTBR="@comment "
.endif
.if ${PORT_OPTIONS:MLANG_RU}
PLIST_SUB+=	LANG_RU=""
.else
PLIST_SUB+=	LANG_RU="@comment "
.endif
.if !empty(PORT_OPTIONS:MLANG_DE) && !empty(PORT_OPTIONS:MLANG_FR) && !empty(PORT_OPTIONS:MLANG_PTBR) && !empty(PORT_OPTIONS:MLANG_RU)
PLIST_SUB+=	TRANSLATIONS=""
.else
PLIST_SUB+=	TRANSLATIONS="@comment "
.endif

do-configure:
	( cd ${WRKSRC}/qt && \
		${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${SPEC} qscintilla.pro )

post-configure:
	( cd ${WRKSRC}/qt && \
		${CAT} qscintilla.pro | ${GREP} -v DESTDIR > qscintilla.tmp && \
		${CAT} Makefile | ${GREP} -v DEL_FILE | ${GREP} -v MOVE | \
			${GREP} -v DESTDIR > Makefile.tmp && \
		${MV} qscintilla.tmp qscintilla.pro && \
		${MV} Makefile.tmp Makefile && \
		cd ${WRKSRC}/designer && \
		${CAT} designer.pro | ${GREP} -v lqscintilla > designer.tmp && \
		${ECHO} "INCPATH += ${LOCALBASE}/include ../qt" >> \
			designer.tmp && \
		${ECHO} "LIBS += -L../qt -L${LOCALBASE}/lib -lqscintilla" >> \
			designer.tmp && \
		${ECHO} "DESTDIR = ." >> designer.tmp && \
		${MV} designer.tmp designer.pro )

do-build:
	( cd ${WRKSRC}/qt && ${SETENV} ${MAKE_ENV} ${MAKE} )

post-build:
.if ${PORT_OPTIONS:MDESIGNER_PLUGIN}
	( cd ${WRKSRC}/designer && ${SETENV} ${MAKE_ENV} \
		${QMAKE} -spec ${SPEC} designer.pro && ${MAKE} )
.endif

do-install:
	( cd ${WRKSRC} && \
		${INSTALL_DATA} qt/qextscintilla*.h ${PREFIX}/include && \
		${INSTALL_DATA} qt/libqscintilla.so.7.0.1 \
			${PREFIX}/lib/libqscintilla.so.7 && \
		${LN} -sf ${PREFIX}/lib/libqscintilla.so.7 \
			${PREFIX}/lib/libqscintilla.so )
.if ${PORT_OPTIONS:MDESIGNER_PLUGIN}
	( cd ${WRKSRC} && \
		${INSTALL_DATA} designer/libqscintillaplugin.so ${PLUGINDIR} )
.endif
.if !empty(PORT_OPTIONS:MLANG_DE) || !empty(PORT_OPTIONS:MLANG_FR) || !empty(PORT_OPTIONS:MLANG_PTBR) || !empty(PORT_OPTIONS:MLANG_RU)
	${MKDIR} -m 0755 ${DATADIR}/translations
.endif
.if ${PORT_OPTIONS:MLANG_DE}
	( cd ${WRKSRC} && \
		${INSTALL_DATA} qt/qscintilla_de.qm ${DATADIR}/translations )
.endif
.if ${PORT_OPTIONS:MLANG_FR}
	( cd ${WRKSRC} && \
		${INSTALL_DATA} qt/qscintilla_fr.qm ${DATADIR}/translations )
.endif
.if ${PORT_OPTIONS:MLANG_PTBR}
	( cd ${WRKSRC} && \
		${INSTALL_DATA} qt/qscintilla_pt_br.qm ${DATADIR}/translations )
.endif
.if ${PORT_OPTIONS:MLANG_RU}
	( cd ${WRKSRC} && \
		${INSTALL_DATA} qt/qscintilla_ru.qm ${DATADIR}/translations )
.endif
.if ${PORT_OPTIONS:MDOCS}
	( cd ${WRKSRC} && \
		${MKDIR} -m 0755 ${DOCSDIR}/html ${DOCSDIR}/Scintilla && \
		${INSTALL_DATA} ChangeLog NEWS README ${DOCSDIR} && \
		${INSTALL_DATA} doc/qscintilla.dxy ${DOCSDIR} && \
		${INSTALL_DATA} doc/html/* ${DOCSDIR}/html &&  \
		${INSTALL_DATA} doc/Scintilla/* ${DOCSDIR}/Scintilla )
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	( cd ${WRKSRC} && \
		${MKDIR} -m 0755 ${EXAMPLESDIR} && \
		${INSTALL_DATA} example/* ${EXAMPLESDIR} )
.endif

.include <bsd.port.post.mk>
