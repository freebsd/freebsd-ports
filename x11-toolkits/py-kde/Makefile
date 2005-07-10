# New ports collection makefile for:	PyKDE
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	4.0.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits kde python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/snapshots/PyKDE/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyKDE-snapshot20050628

MAINTAINER=	danny@ricin.com
COMMENT=	Python bindings for KDE3

BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_KDELIBS_VER=3
USE_REINPLACE=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}
NO_FILTER_SHLIBS=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	-k ${LOCALBASE} -v ${PREFIX}/share/sip -d ${PYTHONPREFIX_SITELIBDIR}

.if ${ARCH} != "i386"
CONFIGURE_ARGS+=	-j 2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/bin/python#${PYTHON_CMD}#' ${WRKSRC}/postproc

do-configure:
	@( cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${CONFIGURE_ARGS} )

pre-install:
	@${REINPLACE_CMD} -e "s,${SETENV} python,${PYTHON_CMD}," \
		${WRKSRC}/contrib/kdepyuic

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR} ${EXAMPLESDIR}/templates
	@( cd ${WRKSRC}/examples && ${TAR} -cf - . ) | \
		( cd ${EXAMPLESDIR} && ${TAR} -xf - )
	@( cd ${WRKSRC}/templates && ${TAR} -cf - . ) | \
		( cd ${EXAMPLESDIR}/templates && ${TAR} -xf - )
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${EXAMPLESDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/kdepyuic ${PREFIX}/bin
	@${PYTHON_CMD} -c "import pykdeconfig, dcopexport"
	@${PYTHON_CMD} -O -c "import pykdeconfig, dcopexport"

.include <bsd.port.post.mk>
