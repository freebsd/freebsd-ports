# New ports collection makefile for:	gmrun
# Date created:				26 September 2002
# Whom:					Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	gmrun
PORTVERSION=	0.8.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	adamw@FreeBSD.org

BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gtk12 glib12

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|PACKAGE_DATA_DIR\"|\"${PREFIX}/etc|' ${WRKSRC}/src/prefs.cc

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/gmrun ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/config/gmrunrc ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
