# New ports collection makefile for:	PyQt
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$

PORTNAME=	qt
PORTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/PyQt/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyQt-x11-gpl-${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org

LIB_DEPENDS=	sip.9:${PORTSDIR}/devel/sip
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libsip.so:${PORTSDIR}/devel/py-sip

USE_QT_VER=	3
USE_PYTHON=	yes
USE_REINPLACE=	yes

ALL_TARGET=	all install install-eric

NO_FILTER_SHLIBS=	yes

do-configure:
	@${MKDIR} ${WRKDIR}/binaries
	@${MKDIR} ${WRKDIR}/modules
	@(cd ${WRKSRC} && ${PYTHON_CMD} build.py -c -e ${LOCALBASE}/include/sip \
		-s ${LOCALBASE}/lib -q ${X11BASE} -b ${WRKDIR}/binaries \
		-d ${WRKDIR}/modules )

pre-build:
	@${REINPLACE_CMD} -e 's#LIBS *= $$(SUBLIBS)#LIBS = $$(SUBLIBS) -L${WRKDIR}/modules -Wl,-rpath,${PYTHONPREFIX_SITELIBDIR}#' ${WRKSRC}/*/Makefile

do-install:
	@${CP} ${WRKDIR}/binaries/* ${PREFIX}/bin/
	@( cd ${WRKDIR}/modules/ && ${TAR} -cf - . ) | \
		( cd ${PYTHONPREFIX_SITELIBDIR} && ${TAR} xf - )

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PYTHONPREFIX_SITELIBDIR}/eric

.include <bsd.port.mk>
