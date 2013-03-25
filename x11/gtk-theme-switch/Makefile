# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtk-theme-switch
PORTVERSION=	1.0.1
PORTREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	http://www.muhri.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A command line tool for switching GTK+ themes

USE_GNOME=	gtk12
USE_GMAKE=	yes

MAN1=		gtk-theme-switch.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${PREFIX}/share/gtk-theme-switch
	${INSTALL_MAN} ${WRKSRC}/readme ${PREFIX}/share/gtk-theme-switch/README
.endif

.include <bsd.port.mk>
