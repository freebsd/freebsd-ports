# New ports collection makefile for:	PyQt
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$

PORTNAME=	qt
PORTVERSION=	3.7
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/PyQt/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyQt-x11-gpl-${PORTVERSION}

MAINTAINER=	osgene@web.de
COMMENT=	Python Bindings for Qt

LIB_DEPENDS=	sip.10:${PORTSDIR}/devel/sip
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libsip.so:${PORTSDIR}/devel/py-sip

USE_QT_VER=	3
USE_PYTHON=	yes
NO_FILTER_SHLIBS=	yes
USE_REINPLACE=	yes

ALL_TARGET=	all install

do-configure:
	@${MKDIR} ${WRKDIR}/binaries
	@${MKDIR} ${WRKDIR}/modules
	@(cd ${WRKSRC} && ${ECHO} "yes" | ${PYTHON_CMD} build.py -c \
		-e ${LOCALBASE}/include/sip -s ${LOCALBASE}/lib \
		-q ${X11BASE} -b ${WRKDIR}/binaries -d ${WRKDIR}/modules )

pre-build:
	@${REINPLACE_CMD} -e 's#LIBS *= $$(SUBLIBS)#LIBS = $$(SUBLIBS) -L${WRKDIR}/modules -Wl,-rpath,${PYTHONPREFIX_SITELIBDIR}#' ${WRKSRC}/*/Makefile

do-install:
	@${CP} ${WRKDIR}/binaries/* ${PREFIX}/bin/
	${CP} -Rf ${WRKDIR}/modules/* ${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
