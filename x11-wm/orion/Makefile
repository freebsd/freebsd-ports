# New ports collection makefile for:	orion
# Date created:				14 July 2004
# Whom:					bkhl@elektrubadur.se
#
# $FreeBSD$
#

PORTNAME=	orion
PORTVERSION=	0.2
CATEGORIES=	x11-wm scheme
MASTER_SITES=	ftp://ftp.scsh.net/pub/scsh/packages/orion-wm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 window manager written in Scheme

RUN_DEPENDS=	${LOCALBASE}/lib/scsh/0.6/module-system:${PORTSDIR}/devel/sunterlib \
		${LOCALBASE}/lib/scsh/0.6/scx:${PORTSDIR}/x11-toolkits/scx

USE_X_PREFIX=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC}; ./install.scm --prefix=${PREFIX})

post-install:
	${RM} -rf ${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/user.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
