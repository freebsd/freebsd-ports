# New ports collection makefile for:	PyKDE
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	3.11.r1
CATEGORIES=	x11-toolkits kde python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/PyKDE2/ \
		http://www.river-bank.demon.co.uk/download/PyQt/:qt
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyKDE-3.11rc1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} PyQt-x11-gpl-${PYQTVERSION}${EXTRACT_SUFX}:qt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Bindings for KDE

BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt

USE_PYTHON=	yes
USE_KDELIBS_VER=3
USE_REINPLACE=	yes

PYQTVERSION=	3.11
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}

NO_FILTER_SHLIBS=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on 4.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/bin/python#${PYTHON_CMD}#' ${WRKSRC}/postproc

do-configure:
	@( cd ${WRKSRC} && ${PYTHON_CMD} configure.py -c \
		-k ${LOCALBASE} \
		-v ${PREFIX}/share/sip \
		-d ${PYTHONPREFIX_SITELIBDIR} )

pre-install:
	@${REINPLACE_CMD} -e "s,/usr/bin/env python,${PYTHON_CMD}," \
		${WRKSRC}/contrib/kdepyuic

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@( cd ${WRKSRC}/examples && ${TAR} -cf - . ) | \
		( cd ${EXAMPLESDIR} && ${TAR} -xf - )
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${EXAMPLESDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${EXAMPLESDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/kdepyuic ${PREFIX}/bin

.include <bsd.port.post.mk>
