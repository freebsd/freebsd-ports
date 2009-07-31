# New ports collection makefile for:	qscintilla
# Date created:				2003-08-02
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	qscintilla
PORTVERSION=	${QSCI1_VERSION}
PORTREVISION=	5
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITES_QSCI1}
DISTNAME=	${QSCI1_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QT port of the Scintilla C++ editor class

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}"
USE_LDCONFIG=	yes

OPTIONS=	DESIGNER_PLUGIN "Install plugin for Qt Designer" on \
		DOCS "Install documentation" on \
		EXAMPLES "Install examples" on \
		LANG_DE "Install German translation" on \
		LANG_FR "Install French translation" on \
		LANG_PTBR "Install Brazilian Portuguese translation" on \
		LANG_RU "Install Russian translation" on

QMAKE=		${LOCALBASE}/bin/qmake
SPEC=		${LOCALBASE}/share/qt/mkspecs/freebsd-g++
PLUGINDIR=	${LOCALBASE}/lib/plugins/designer

.include "../../devel/py-sip/files/bsd.pyqt.mk"
.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS) || defined(WITHOUT_DOCS)
PLIST_SUB+=	DOCS="@comment "
.else
PLIST_SUB+=	DOCS=""
.endif
.if defined(NOPORTEXAMPLES) || defined(WITHOUT_EXAMPLES)
PLIST_SUB+=	EXAMPLES="@comment "
.else
PLIST_SUB+=	EXAMPLES=""
.endif
.if defined(WITHOUT_DESIGNER_PLUGIN)
PLIST_SUB+=	DESIGNER_PLUGIN="@comment "
.else
PLIST_SUB+=	DESIGNER_PLUGIN=""
.endif
.if defined(WITHOUT_LANG_DE)
PLIST_SUB+=	LANG_DE="@comment "
.else
PLIST_SUB+=	LANG_DE=""
.endif
.if defined(WITHOUT_LANG_FR)
PLIST_SUB+=	LANG_FR="@comment "
.else
PLIST_SUB+=	LANG_FR=""
.endif
.if defined(WITHOUT_LANG_PTBR)
PLIST_SUB+=	LANG_PTBR="@comment "
.else
PLIST_SUB+=	LANG_PTBR=""
.endif
.if defined(WITHOUT_LANG_RU)
PLIST_SUB+=	LANG_RU="@comment "
.else
PLIST_SUB+=	LANG_RU=""
.endif
.if defined(WITHOUT_LANG_DE) && defined(WITHOUT_LANG_FR) && defined(WITHOUT_LANG_PTBR) && defined(WITHOUT_LANG_RU)
PLIST_SUB+=	TRANSLATIONS="@comment "
.else
PLIST_SUB+=	TRANSLATIONS=""
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
.if !defined(WITHOUT_DESIGNER_PLUGIN)
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
.if !defined(WITHOUT_DESIGNER_PLUGIN)
	( cd ${WRKSRC} && \
		${INSTALL_DATA} designer/libqscintillaplugin.so ${PLUGINDIR} )
.endif
.if !defined(WITHOUT_LANG_DE) || !defined(WITHOUT_LANG_FR) || !defined(WITHOUT_LANG_PTBR) || !defined(WITHOUT_LANG_RU)
	${MKDIR} -m 0755 ${DATADIR}/translations
.endif
.if !defined(WITHOUT_LANG_DE)
	( cd ${WRKSRC} && \
		${INSTALL_DATA} qt/qscintilla_de.qm ${DATADIR}/translations )
.endif
.if !defined(WITHOUT_LANG_FR)
	( cd ${WRKSRC} && \
		${INSTALL_DATA} qt/qscintilla_fr.qm ${DATADIR}/translations )
.endif
.if !defined(WITHOUT_LANG_PTBR)
	( cd ${WRKSRC} && \
		${INSTALL_DATA} qt/qscintilla_pt_br.qm ${DATADIR}/translations )
.endif
.if !defined(WITHOUT_LANG_RU)
	( cd ${WRKSRC} && \
		${INSTALL_DATA} qt/qscintilla_ru.qm ${DATADIR}/translations )
.endif
.if !defined(NOPORTDOCS) && !defined(WITHOUT_DOCS)
	( cd ${WRKSRC} && \
		${MKDIR} -m 0755 ${DOCSDIR}/html ${DOCSDIR}/Scintilla && \
		${INSTALL_DATA} ChangeLog NEWS README ${DOCSDIR} && \
		${INSTALL_DATA} doc/qscintilla.dxy ${DOCSDIR} && \
		${INSTALL_DATA} doc/html/* ${DOCSDIR}/html &&  \
		${INSTALL_DATA} doc/Scintilla/* ${DOCSDIR}/Scintilla )
.endif
.if !defined(NOPORTEXAMPLES) && !defined(WITHOUT_EXAMPLES)
	( cd ${WRKSRC} && \
		${MKDIR} -m 0755 ${EXAMPLESDIR} && \
		${INSTALL_DATA} example/* ${EXAMPLESDIR} )
.endif

.include <bsd.port.post.mk>
