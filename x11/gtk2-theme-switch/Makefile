# New ports collection makefile for:	gtk-theme-switch
# Date Created:		Thu Nov 13 01:44:28 EST 2003
# Whom:			Andrew J. Caines <A.J.Caines@halplant.com>
#
# $FreeBSD$
#

PORTNAME=	gtk2-theme-switch
PORTVERSION=	2.0.0.r2
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://www.muhri.net/
DISTNAME=	${PORTNAME:S/gtk2/gtk/}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	A command line tool for switching GTK themes

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes

MAN1=		gtk2-theme-switch.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/switch2  ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/switch.1 ${MANPREFIX}/man/man1/${PORTNAME}.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
