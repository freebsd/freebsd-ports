# New ports collection makefile for:    keylaunch
# Date created:         Sat Nov 17 10:10:07 CDT 2001
# Whom:                 mwm@mired.org
#
# $FreeBSD$
#

PORTNAME=	keylaunch
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.mired.org/downloads/

MAINTAINER=	mwm@mired.org
COMMENT=	An X utility for binding commands to a hot key

WRKSRC=		${WRKDIR}/keylaunch
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes

PKGMESSAGE=	${WRKSRC}/pkg-message

post-patch:
	@${PERL} -pi -e 's,%%X11BASE%%,${X11BASE},g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keylaunch ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example_rc ${EXAMPLESDIR}/keylaunch.rc

post-install:
	@${SED} -e 's;/usr/X11R6;${PREFIX};g' < ${FILESDIR}/pkg-message.in > \
		${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
