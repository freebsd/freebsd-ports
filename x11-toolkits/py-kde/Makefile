# New ports collection makefile for:	PyKDE
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	3.3.2
PORTREVISION=	2
CATEGORIES=	x11-toolkits kde python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/PyKDE2/ \
		http://www.river-bank.demon.co.uk/download/PyQt/:qt
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyKDE-${PORTVERSION}-3
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} PyQt-x11-gpl-${PYQTVERSION}${EXTRACT_SUFX}:qt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Bindings for KDE

BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt

BROKEN=		"Checksum mismatch; will be removed after Feb 2"

WRKSRC=		${WRKDIR}/PyKDE-${PORTVERSION}

USE_PYTHON=	yes
USE_KDELIBS_VER=3
USE_REINPLACE=	yes

PYQTVERSION=	3.4

ALL_TARGET=	all install

MODULES=	dcop kdecore kdesu kdefx kdeui kio kfile kparts khtml kjs kspell kdeprint

PLIST_SUB+=	PKGBASE=${PKGBASE}

NO_FILTER_SHLIBS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/bin/python#${PYTHON_CMD}#' ${WRKSRC}/postproc

do-configure:
	@${MKDIR} ${WRKDIR}/modules
	@( cd ${WRKSRC} && env KDEDIR=${PREFIX} ${PYTHON_CMD} build.py -c \
		-e ${PREFIX}/include/sip -q ${X11BASE} \
		-v ${WRKDIR}/PyQt-x11-gpl-3.4/sip -d ${WRKDIR}/modules )
	@${REINPLACE_CMD} -e 's#LIBS *= $$(SUBLIBS)#LIBS = $$(SUBLIBS) -L${WRKDIR}/modules -Wl,-rpath,${PYTHONPREFIX_SITELIBDIR}#' ${WRKSRC}/*/Makefile
	@${REINPLACE_CMD} -e 's#atoll (s)#strtoll (s, NULL, 10)#' ${WRKSRC}/kio/kiohuge.cpp

pre-build:
.for module in ${MODULES}
	( cd ${WRKSRC}/${module} && ${MAKE} ${ALL_TARGET} )
.endfor

pre-install:
	@(${ECHO} "#!${PYTHON_CMD}"; ${CAT} ${WRKSRC}/kdepyuic.py) > ${WRKSRC}/kdepyuic

do-install:
	@( cd ${WRKDIR}/modules/ && ${TAR} -cf - . ) | \
		( cd ${PYTHONPREFIX_SITELIBDIR} && ${TAR} xf - )
	@${MKDIR} ${PREFIX}/share/examples/${PKGBASE}
	@( cd ${WRKSRC}/examples && ${TAR} -cf - . ) | \
		( cd ${PREFIX}/share/examples/${PKGBASE} && ${TAR} -xf - )
	@${INSTALL_SCRIPT} ${WRKSRC}/kdepyuic ${PREFIX}/bin

.include <bsd.port.mk>
