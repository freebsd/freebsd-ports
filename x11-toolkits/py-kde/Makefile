# New ports collection makefile for:	PyKDE
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	3.11.3
CATEGORIES=	x11-toolkits kde python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/PyKDE2/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyKDE-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danny@ricin.com
COMMENT=	Python Bindings for KDE3

BROKEN=		"Does not compile with KDE >= 3.3.1"

BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.3
USE_KDELIBS_VER=3
USE_REINPLACE=	yes

PYQTVERSION=	3.13
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}

NO_FILTER_SHLIBS=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/bin/python#${PYTHON_CMD}#' ${WRKSRC}/postproc

do-configure:
	@( cd ${WRKSRC} && ${PYTHON_CMD} configure.py -c \
		-k ${LOCALBASE} \
		-v ${PREFIX}/share/sip \
		-d ${PYTHONPREFIX_SITELIBDIR} )

pre-install:
	@${REINPLACE_CMD} -e "s,${SETENV} python,${PYTHON_CMD}," \
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
	@${PYTHON_CMD} -c "import pykdeconfig, dcopexport"
	@${PYTHON_CMD} -O -c "import pykdeconfig, dcopexport"

.include <bsd.port.post.mk>
