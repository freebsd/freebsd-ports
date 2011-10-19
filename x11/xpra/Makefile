# New ports collection makefile for:	xpra
# Date created:		2011-01-11
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xpra
PORTVERSION=	0.0.7.28
CATEGORIES=	x11
MASTER_SITES=	http://winswitch.org/src/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Xpra gives you persistent remote applications for X

BUILD_DEPENDS=	cython:${PORTSDIR}/lang/cython \
		ipython:${PORTSDIR}/devel/ipython \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	cython:${PORTSDIR}/lang/cython \
		ipython:${PORTSDIR}/devel/ipython \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		Xvfb:${PORTSDIR}/x11-servers/xorg-vfbserver

MAN1=		${PORTNAME}.1
PORTDOCS=	README.wimpiggy README.xpra
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_XORG=	x11 xext xtst xfixes xcomposite xdamage

do-build:
	( cd ${WRKSRC} ; ./do-build )

do-install:
	${INSTALL_SCRIPT}  ${WRKSRC}/install/bin/xpra                     ${PREFIX}/bin
	${RM} -rf ${WRKSRC}/install/lib/python/xpra/win32
	${RM} -rf ${WRKSRC}/install/lib/python/xpra/darwin
	(cd ${WRKSRC}/install/lib/python/xpra && ${COPYTREE_SHARE} \* ${PYTHON_SITELIBDIR}/xpra )
	(cd ${WRKSRC}/install/lib/python/wimpiggy && ${COPYTREE_SHARE} \* ${PYTHON_SITELIBDIR}/wimpiggy )
	${INSTALL_MAN}     ${WRKSRC}/install/share/man/man1/${PORTNAME}.1 ${MANPREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.wimpiggy ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.xpra ${DOCSDIR}
.endif

.include <bsd.port.mk>
