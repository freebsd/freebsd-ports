# New ports collection makefile for:	PyQt
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$

PORTNAME=	qt
PORTVERSION=	3.14.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/snapshots/PyQt/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyQt-x11-gpl-snapshot-20050709

MAINTAINER=	danny@ricin.com
COMMENT=	Python bindings for the Qt toolkit

LIB_DEPENDS=	qscintilla.6:${PORTSDIR}/x11-toolkits/qscintilla
BUILD_DEPENDS=	${LOCALBASE}/bin/sip:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_QT_VER=	3
USE_PYTHON=	yes
USE_REINPLACE=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_OPENGL)
PLIST_SUB+=	GL="@comment "
.else
PLIST_SUB+=	GL=""
.endif

do-configure:
	@( cd ${WRKSRC} && ${ECHO} "yes" | ${PYTHON_CMD} configure.py \
		-b ${PREFIX}/bin -d ${PYTHONPREFIX_SITELIBDIR} \
		-n ${X11BASE}/include -o ${X11BASE}/lib \
		-v ${PREFIX}/share/sip )

.if ${OSVERSION} < 500000
post-configure:
	@${REINPLACE_CMD} -e \
		's|static_cast<sipQTable::sipEditMode>(QTable::editMode())|\
				(sipQTable::sipEditMode) QTable::editMode()|' \
				${WRKSRC}/qttable/sipqttableQTable.cpp
	@${REINPLACE_CMD} -e \
		's|static_cast<sipQDataTable::sipEditMode>(QTable::editMode())|\
				(sipQDataTable::sipEditMode) QTable::editMode()|' \
				${WRKSRC}/qtsql/sipqtsqlQDataTable.cpp
.endif

post-install:
	@${PYTHON_CMD} -c "import pyqtconfig"
	@${PYTHON_CMD} -O -c "import pyqtconfig"
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR} ${EXAMPLESDIR}/SQL ${EXAMPLESDIR}/canvas \
		${EXAMPLESDIR}/i18n ${EXAMPLESDIR}/webbrowser
	@( cd ${WRKSRC}/examples3 && ${TAR} -cf - . ) | \
		( cd ${EXAMPLESDIR} && ${TAR} -xf - )
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${EXAMPLESDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
