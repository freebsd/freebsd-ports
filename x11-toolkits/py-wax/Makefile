# New ports collection makefile for:	wax
# Date created:		2006-04-03
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	wax
PORTVERSION=	0.3.33
PORTREVISION=	4
CATEGORIES=	x11-toolkits devel python
MASTER_SITES=	SF/${PORTNAME}gui/${PORTNAME}gui/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A user-friendly layer on top of wxPython

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/${WX_PYTHON_DIR}/wxPython/_wx.py:${PORTSDIR}/x11-toolkits/py-wxPython26

NO_BUILD=	yes
USE_PYTHON=	yes

DATADIR=	${PYTHON_SITELIBDIR}

FIND_DIRS=	-type d \! -empty
FIND_DATA=	-type f
FIND_DELETE=	\( -name "*.txt" -and -maxdepth 2 \)

.if !defined(WITH_EXAMPLES)
PLIST_SUB=	PORTEXAMPLES="@comment "
.else
PLIST_SUB=	PORTEXAMPLES=""
.endif

do-install:
	@cd ${WRKSRC} && ${FIND} . ${FIND_DIRS} -exec ${MKDIR} ${DATADIR}/{} \;
	@cd ${WRKSRC} && ${FIND} . ${FIND_DELETE} -delete
	@cd ${WRKSRC} && ${FIND} . ${FIND_DATA} -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
.if !defined(WITH_EXAMPLES)
	${RM} -r ${DATADIR}/${PORTNAME}/examples
.else
	${MV} ${DATADIR}/${PORTNAME}/examples ${EXAMPLESDIR}
.endif

.if defined(WITH_UNICODE)
WX_PYTHON_DIR=	wx-2.6-gtk2-unicode
.else
WX_PYTHON_DIR=	wx-2.6-gtk2-ansi
.endif

.include <bsd.port.mk>
